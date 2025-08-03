# ft_transcendence - 42 Cursus Final Project
# Makefile for Docker Compose orchestration

# Default Docker Compose file
COMPOSE_FILE = docker-compose.yml

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m # No Color

# Default target
all: up

# Build and start all services
up:
	@echo "$(GREEN)🚀 Building and starting ft_transcendence services...$(NC)"
	@docker-compose -f $(COMPOSE_FILE) up -d --build
	@echo "$(GREEN)✅ Services are running!$(NC)"
	@echo "$(YELLOW)Frontend: https://localhost:3500$(NC)"
	@echo "$(YELLOW)Backend API: https://localhost:8000$(NC)"
	@echo "$(YELLOW)Tournament API: https://localhost:8002$(NC)"

# Start services without building
start:
	@echo "$(GREEN)🔄 Starting ft_transcendence services...$(NC)"
	@docker-compose -f $(COMPOSE_FILE) up -d
	@echo "$(GREEN)✅ Services started!$(NC)"

# Stop all services
stop:
	@echo "$(YELLOW)⏹️  Stopping ft_transcendence services...$(NC)"
	@docker-compose -f $(COMPOSE_FILE) stop
	@echo "$(GREEN)✅ Services stopped!$(NC)"

# Stop and remove containers
down:
	@echo "$(YELLOW)⬇️  Stopping and removing ft_transcendence containers...$(NC)"
	@docker-compose -f $(COMPOSE_FILE) down
	@echo "$(GREEN)✅ Containers removed!$(NC)"

# Restart services (stop + start)
restart: stop start

# Rebuild and restart everything
re: clean up

# Show service status
status:
	@echo "$(GREEN)📊 Service Status:$(NC)"
	@docker-compose -f $(COMPOSE_FILE) ps

# Show logs for all services
logs:
	@docker-compose -f $(COMPOSE_FILE) logs -f

# Show logs for specific service (usage: make logs-web, make logs-frontend, etc.)
logs-%:
	@docker-compose -f $(COMPOSE_FILE) logs -f $*

# Open shell in running containers
shell-web:
	@docker exec -it transcendence-backend bash

shell-tournament:
	@docker exec -it transcendence-tournaments bash

shell-frontend:
	@docker exec -it transcendence-frontend bash

# Database commands
db-migrate:
	@echo "$(GREEN)🔄 Running database migrations...$(NC)"
	@docker exec -it transcendence-backend python manage.py migrate
	@docker exec -it transcendence-tournaments python manage.py migrate
	@echo "$(GREEN)✅ Migrations completed!$(NC)"

# Complete cleanup (containers, volumes, images, networks)
clean:
	@echo "$(RED)🧹 Performing complete Docker cleanup...$(NC)"
	@echo "$(YELLOW)⚠️  This will remove ALL Docker resources!$(NC)"
	@if docker ps -qa | grep -q .; then \
		echo "$(YELLOW)Stopping containers...$(NC)"; \
		docker stop $$(docker ps -qa); \
		echo "$(YELLOW)Removing containers...$(NC)"; \
		docker rm $$(docker ps -qa); \
	fi
	@if docker volume ls -q | grep -q .; then \
		echo "$(YELLOW)Removing volumes...$(NC)"; \
		docker volume rm $$(docker volume ls -q); \
	fi
	@if docker images -qa | grep -q .; then \
		echo "$(YELLOW)Removing images...$(NC)"; \
		docker rmi -f $$(docker images -qa); \
	fi
	@if docker network ls --format '{{.Name}}' | grep -v 'bridge\|host\|none' | grep -q .; then \
		echo "$(YELLOW)Removing networks...$(NC)"; \
		docker network rm $$(docker network ls --format '{{.Name}}' | grep -v 'bridge\|host\|none'); \
	fi
	@echo "$(GREEN)✅ Docker cleanup completed!$(NC)"

# Project-specific cleanup (only ft_transcendence containers and volumes)
clean-project:
	@echo "$(YELLOW)🧹 Cleaning ft_transcendence project resources...$(NC)"
	@docker-compose -f $(COMPOSE_FILE) down -v --remove-orphans
	@docker system prune -f
	@echo "$(GREEN)✅ Project cleanup completed!$(NC)"

# Development helpers
dev-setup: up db-migrate
	@echo "$(GREEN)🛠️  Development environment ready!$(NC)"

# Show help
help:
	@echo "$(GREEN)ft_transcendence - Available Commands:$(NC)"
	@echo ""
	@echo "$(YELLOW)🚀 Main Commands:$(NC)"
	@echo "  make up          - Build and start all services"
	@echo "  make start       - Start services without building"
	@echo "  make stop        - Stop all services"
	@echo "  make down        - Stop and remove containers"
	@echo "  make restart     - Restart services"
	@echo "  make re          - Clean and rebuild everything"
	@echo ""
	@echo "$(YELLOW)📊 Monitoring:$(NC)"
	@echo "  make status      - Show service status"
	@echo "  make logs        - Show logs for all services"
	@echo "  make logs-web    - Show logs for web service"
	@echo "  make logs-frontend - Show logs for frontend service"
	@echo "  make logs-tournament - Show logs for tournament service"
	@echo ""
	@echo "$(YELLOW)🔧 Development:$(NC)"
	@echo "  make shell-web       - Open shell in web container"
	@echo "  make shell-frontend  - Open shell in frontend container"
	@echo "  make shell-tournament - Open shell in tournament container"
	@echo "  make db-migrate      - Run database migrations"
	@echo "  make dev-setup       - Complete development setup"
	@echo ""
	@echo "$(YELLOW)🧹 Cleanup:$(NC)"
	@echo "  make clean           - Complete Docker cleanup (ALL resources)"
	@echo "  make clean-project   - Clean only project resources"
	@echo ""
	@echo "$(YELLOW)🔗 URLs:$(NC)"
	@echo "  Frontend:        https://localhost:3500"
	@echo "  Backend API:     https://localhost:8000"
	@echo "  Tournament API:  https://localhost:8002"

.PHONY: all up start stop down restart re status logs logs-% shell-web shell-tournament shell-frontend db-migrate clean clean-project dev-setup help