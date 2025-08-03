# 🔍 Minishell Parsing

This document provides a detailed explanation of the parsing algorithm and tokenization process used in minishell.

## 📝 Overview

The minishell parser implements a recursive descent parser that converts user input into an Abstract Syntax Tree (AST) of executable commands. The parsing process consists of several stages:

1. **Lexical Analysis** (Tokenization)
2. **Syntax Analysis** (Validation)
3. **Semantic Analysis** (Parsing)
4. **AST Construction**

## 🎯 Grammar Definition

### Formal Grammar (Extended BNF)
```
command_line    ::= pipeline
pipeline        ::= simple_command ('|' simple_command)*
simple_command  ::= (redirection)* word (word)*
redirection     ::= '<' word | '>' word | '>>' word | '<<' word
word            ::= quoted_string | unquoted_string | variable
quoted_string   ::= '"' (character | variable)* '"' | "'" character* "'"
variable        ::= '$' identifier
identifier      ::= [a-zA-Z_][a-zA-Z0-9_]*
```

### Operator Precedence
1. **Redirections** (`<`, `>`, `>>`, `<<`) - Highest
2. **Pipes** (`|`) - Lower
3. **Words and Arguments** - Lowest

## 🔤 Tokenization Process

### Token Types
```c
#define TOKEN_WORD      'w'
#define TOKEN_PIPE      '|'
#define TOKEN_REDIR_IN  '<'
#define TOKEN_REDIR_OUT '>'
#define TOKEN_APPEND    'a'   // >>
#define TOKEN_HEREDOC   'h'   // <<
#define TOKEN_EOF       'e'
```

### Tokenization Algorithm

#### 1. Main Tokenizer Function
```c
int gettoken(char **ps, char *es, char **q, char **eq)
{
    skip_spaces(ps, es);    // Skip whitespace
    
    if (*ps >= es)
        return TOKEN_EOF;
        
    switch (**ps) {
        case '|':
            return handle_pipe(ps, q, eq);
        case '<':
            return handle_input_redir(ps, es, q, eq);
        case '>':
            return handle_output_redir(ps, es, q, eq);
        default:
            return handle_word(ps, es, q, eq);
    }
}
```

#### 2. Word Tokenization
```c
int handle_word(char **ps, char *es, char **q, char **eq)
{
    *q = *ps;
    
    while (*ps < es && !is_whitespace(**ps) && !is_special(**ps)) {
        if (**ps == '\'' || **ps == '"')
            handle_quotes(ps, es);
        else
            (*ps)++;
    }
    
    *eq = *ps;
    return TOKEN_WORD;
}
```

#### 3. Quote Handling
```c
void handle_quotes(char **ps, char *es)
{
    char quote = **ps;
    (*ps)++;  // Skip opening quote
    
    while (*ps < es && **ps != quote) {
        if (quote == '"' && **ps == '\\')
            (*ps)++;  // Handle escape sequences in double quotes
        (*ps)++;
    }
    
    if (*ps < es)
        (*ps)++;  // Skip closing quote
}
```

## 🌳 Parsing Algorithm

### Recursive Descent Structure

The parser follows a top-down approach, starting from the highest-level construct and recursively parsing sub-components.

```
parsecmd()
    └── parseline()
        └── parsepipe()
            └── parseexec()
                └── parseredirs()
```

### 1. Command Parser Entry Point
```c
t_cmd *parsecmd(char *s, t_shell *shell)
{
    char *es = s + strlen(s);
    t_cmd *cmd = parseline(&s, es, shell);
    
    if (peek(&s, es, "") != 0) {
        syntax_error('unexpected token');
        return NULL;
    }
    
    return nulterminate(cmd);
}
```

### 2. Pipeline Parser
```c
t_cmd *parsepipe(char **ps, char *es, t_shell *shell)
{
    t_cmd *cmd = parseexec(ps, es, shell);
    
    if (peek(ps, es, "|")) {
        gettoken(ps, es, 0, 0);  // Consume '|'
        cmd = pipecmd(cmd, parsepipe(ps, es, shell));
        shell->is_pipe = true;
    }
    
    return cmd;
}
```

### 3. Simple Command Parser
```c
t_cmd *parseexec(char **ps, char *es, t_shell *shell)
{
    t_execcmd *cmd = (t_execcmd*)execcmd();
    int argc = 0;
    char *q, *eq;
    int tok;
    
    cmd = (t_execcmd*)parseredirs((t_cmd*)cmd, ps, es, shell);
    
    while (!peek(ps, es, "|")) {
        if ((tok = gettoken(ps, es, &q, &eq)) == 0)
            break;
            
        if (tok != TOKEN_WORD)
            panic("syntax error");
            
        cmd->argv[argc] = q;
        cmd->eargv[argc] = eq;
        argc++;
        
        if (argc >= MAXARGS)
            panic("too many arguments");
            
        cmd = (t_execcmd*)parseredirs((t_cmd*)cmd, ps, es, shell);
    }
    
    cmd->argv[argc] = 0;
    cmd->eargv[argc] = 0;
    
    return (t_cmd*)cmd;
}
```

### 4. Redirection Parser
```c
t_cmd *parseredirs(t_cmd *cmd, char **ps, char *es, t_shell *shell)
{
    int tok;
    char *q, *eq;
    
    while (peek(ps, es, "<>")) {
        tok = gettoken(ps, es, 0, 0);
        
        if (gettoken(ps, es, &q, &eq) != TOKEN_WORD)
            panic("missing file for redirection");
            
        switch (tok) {
            case '<':
                cmd = redircmd(cmd, (t_parse_set){q, eq, O_RDONLY, 0});
                break;
            case '>':
                cmd = redircmd(cmd, (t_parse_set){q, eq, O_WRONLY|O_CREAT|O_TRUNC, 1});
                break;
            case TOKEN_APPEND:
                cmd = redircmd(cmd, (t_parse_set){q, eq, O_WRONLY|O_CREAT|O_APPEND, 1});
                break;
            case TOKEN_HEREDOC:
                cmd = parse_heredoc_cmd(cmd, q, eq, shell);
                break;
        }
    }
    
    return cmd;
}
```

## 🔍 Lookahead Function

The `peek()` function provides lookahead capability without consuming tokens:

```c
int ft_peek(char **ps, char *es, char *toks)
{
    char *s = *ps;
    
    skip_spaces(&s, es);
    
    for (int i = 0; toks[i]; i++) {
        if (s < es && *s == toks[i])
            return toks[i];
    }
    
    return 0;
}
```

## 🌟 Variable Expansion

### Expansion Algorithm
```c
char *expand_env(char *input, t_shell *shell)
{
    char *result = malloc(count_expand(input, shell));
    char *dst = result;
    char *src = input;
    
    while (*src) {
        if (*src == '$' && *(src + 1)) {
            src++;
            char *var_start = src;
            
            // Extract variable name
            while (*src && (isalnum(*src) || *src == '_'))
                src++;
                
            char *var_name = strndup(var_start, src - var_start);
            char *var_value = get_env_value(shell, var_name);
            
            if (var_value) {
                strcpy(dst, var_value);
                dst += strlen(var_value);
            }
            
            free(var_name);
        } else {
            *dst++ = *src++;
        }
    }
    
    *dst = '\0';
    return result;
}
```

### Variable Expansion Rules
1. **`$VAR`**: Standard variable expansion
2. **`"$VAR"`**: Expansion within double quotes
3. **`'$VAR'`**: No expansion within single quotes
4. **`$$`**: Process ID (special case)
5. **`$?`**: Exit status of last command

## 📋 Quote Processing

### Quote Types and Behavior

#### Single Quotes (`'...'`)
- Preserve literal value of all characters
- No variable expansion
- No escape sequences

#### Double Quotes (`"..."`)
- Allow variable expansion
- Preserve literal value except for `$`, `` ` ``, `\`, and `"`
- Handle escape sequences

### Quote Processing Algorithm
```c
bool handle_quotes(char **input)
{
    char *src = *input;
    char *dst = *input;
    bool in_single = false;
    bool in_double = false;
    
    while (*src) {
        if (*src == '\'' && !in_double) {
            in_single = !in_single;
            src++;  // Skip quote character
            continue;
        }
        
        if (*src == '"' && !in_single) {
            in_double = !in_double;
            src++;  // Skip quote character
            continue;
        }
        
        *dst++ = *src++;
    }
    
    *dst = '\0';
    return !in_single && !in_double;  // Return true if quotes are balanced
}
```

## 🎭 Here-Document Processing

### Here-Document Algorithm
```c
char *parse_heredoc(char *delimiter, t_shell *shell, t_parse_set *set)
{
    char *content = NULL;
    char *line;
    size_t total_len = 0;
    
    while ((line = readline("> ")) != NULL) {
        if (strcmp(line, delimiter) == 0) {
            free(line);
            break;
        }
        
        // Expand variables if delimiter is not quoted
        if (!set->quoted_delimiter) {
            char *expanded = expand_env(line, shell);
            free(line);
            line = expanded;
        }
        
        // Append line to content
        size_t line_len = strlen(line);
        content = realloc(content, total_len + line_len + 2);
        strcpy(content + total_len, line);
        content[total_len + line_len] = '\n';
        content[total_len + line_len + 1] = '\0';
        total_len += line_len + 1;
        
        free(line);
    }
    
    return content;
}
```

## ⚠️ Error Handling

### Syntax Error Detection
```c
void syntax_error(char c)
{
    if (c == 0)
        ft_putstr_fd("syntax error: unexpected end of input\n", 2);
    else
        dprintf(2, "syntax error near unexpected token `%c'\n", c);
}
```

### Error Recovery Strategies
1. **Syntax Errors**: Report and abort parsing
2. **Memory Errors**: Clean up and exit gracefully
3. **Quote Errors**: Report unclosed quotes
4. **Redirection Errors**: Validate file arguments

## 🧪 Testing the Parser

### Test Cases

#### Valid Inputs
```bash
echo hello world
ls | grep .c
cat < input.txt > output.txt
echo "Hello $USER"
```

#### Invalid Inputs
```bash
ls |           # Missing command after pipe
cat <          # Missing file for redirection
echo "unclosed # Unclosed quote
```

### Parser Test Framework
```c
void test_parser(char *input, bool should_succeed)
{
    t_shell shell;
    init_shell(&shell);
    
    t_cmd *cmd = parsecmd(input, &shell);
    
    if (should_succeed) {
        assert(cmd != NULL);
        printf("✅ Parse success: %s\n", input);
    } else {
        assert(cmd == NULL);
        printf("✅ Parse failure (expected): %s\n", input);
    }
    
    cleanup_shell(&shell);
}
```

## 📈 Performance Analysis

### Time Complexity
- **Tokenization**: O(n) where n is input length
- **Parsing**: O(n) for linear command structures
- **Variable Expansion**: O(n×m) where m is average variable length

### Space Complexity
- **AST Storage**: O(n) where n is number of commands
- **Token Storage**: O(n) temporary storage
- **Expansion Buffer**: O(m) where m is expanded string length

### Optimization Opportunities
1. **String Interning**: Reuse common strings
2. **Memory Pooling**: Allocate command structures in pools
3. **Lazy Expansion**: Expand variables only when needed

---

This parsing system provides a robust foundation for command interpretation while maintaining clarity and extensibility.
