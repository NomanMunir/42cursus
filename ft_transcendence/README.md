# ft_transcendence

**42 Cursus Final Project - A Modern Web-based Pong Game Platform**

![Pong Game](https://img.shields.io/badge/Game-Pong-blue?style=for-the-badge)
![42](https://img.shields.io/badge/42-Project-black?style=for-the-badge)
![Docker](https://img.shields.io/badge/Docker-Containerized-blue?style=for-the-badge)
![Django](https://img.shields.io/badge/Django-Backend-green?style=for-the-badge)
![JavaScript](https://img.shields.io/badge/JavaScript-Frontend-yellow?style=for-the-badge)

## 🎮 Live Demo

**[🕹️ Play the Game Now!](https://nomanmunir.github.io/ft_transcendence_frontend/)**

Experience the full frontend implementation of our Pong game with all features including AI opponents, tournaments, and multiplayer modes!

## 📖 Project Overview

ft_transcendence is the final project of the 42 Common Core curriculum, representing a complete full-stack web application. This project implements a modern, feature-rich Pong game platform with microservices architecture, real-time gameplay, and comprehensive user management.

### 🏗️ Architecture

The project follows a **microservices architecture** with the following components:

- **Backend Service** (User Management) - Django REST API
- **Tournament Service** (Tournament Management) - Django REST API  
- **Frontend** - Vanilla JavaScript SPA with Bootstrap
- **Databases** - PostgreSQL instances for each service
- **Container Orchestration** - Docker Compose

## ✨ Features

### 🎯 Game Modes
- **Single-Round Mode**: Play against intelligent AI opponents
- **Tournament Mode**: 8-player knockout tournaments with bracket visualization
- **Multiplayer Mode**: Support for 3-4 players simultaneously
- **Real-time Gameplay**: Smooth, responsive game mechanics

### 🌍 User Experience
- **Multi-language Support**: English, German, and Arabic
- **Responsive Design**: Works seamlessly on desktop, tablet, and mobile
- **Cross-browser Compatibility**: Tested across all modern browsers
- **Single Page Application**: Smooth navigation without page reloads

### 🤖 AI Features
- **Intelligent AI Opponents**: Predictive ball tracking and adaptive gameplay
- **Human-like Behavior**: AI plays at human speed with strategic decision making
- **Challenging Gameplay**: Balanced difficulty to ensure engaging matches

### 🏆 Tournament System
- **Automatic Matchmaking**: Intelligent pairing and bracket management
- **Live Updates**: Real-time tournament progression and results
- **Player Registration**: Simple alias-based registration system

## 🚀 Quick Start

### Prerequisites
- Docker and Docker Compose
- Git

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/NomanMunir/42cursus.git
   cd 42cursus/ft_transcendence
   ```

2. **Setup environment**
   ```bash
   cp .env.example .env
   # Edit .env with your configuration
   ```

3. **Start the application**
   ```bash
   make
   # or
   docker compose up --build
   ```

4. **Access the application**
   - Frontend: `https://localhost:3500`
   - Backend API: `https://localhost:8000`
   - Tournament API: `https://localhost:8002`

## 🛠️ Development

### Available Commands

```bash
make up      # Build and start all services
make start   # Start services without building
make down    # Stop all services
make stop    # Stop services without removing containers
make restart # Restart services
make clean   # Complete cleanup (containers, volumes, images, networks)
make re      # Rebuild everything from scratch
make status  # Show service status
make logs    # Show logs for all services
make help    # Show all available commands
```

### Project Structure

```
ft_transcendence/
├── backend/                 # User management service (Django)
│   ├── api/
│   ├── backend/
│   ├── Dockerfile
│   └── requirements.txt
├── tournament-service/      # Tournament management service (Django)
│   ├── tournaments/
│   ├── tournament_api/
│   ├── Dockerfile
│   └── requirements.txt
├── frontend/                # Frontend application (Vanilla JS)
│   ├── assets/
│   ├── components/
│   ├── Dockerfile
│   └── package.json
├── docker-compose.yml       # Container orchestration
├── Makefile                # Development commands
└── README.md               # This file
```

## 🔧 Technical Stack

### Backend
- **Framework**: Django REST Framework
- **Database**: PostgreSQL 16
- **Authentication**: JWT/Session-based
- **API**: RESTful endpoints

### Frontend
- **Core**: Vanilla JavaScript (ES6+)
- **Styling**: Bootstrap 5
- **Graphics**: HTML5 Canvas
- **Architecture**: Modular SPA design

### Infrastructure
- **Containerization**: Docker & Docker Compose
- **Networking**: Custom Docker networks
- **SSL/TLS**: Self-signed certificates for HTTPS
- **Environment**: Environment variable configuration

## 🌐 API Documentation

### User Management API (Port 8000)
- User registration and authentication
- Profile management
- Game statistics and history

### Tournament API (Port 8002)  
- Tournament creation and management
- Bracket generation and updates
- Match results tracking

## 🎨 Frontend Features

### Game Engine
- **Real-time Rendering**: 60 FPS canvas-based gameplay
- **Physics Engine**: Custom collision detection and ball physics
- **Input Management**: Multi-player keyboard input handling
- **State Management**: Modular game state architecture

### UI/UX
- **Responsive Design**: Mobile-first approach with Bootstrap
- **Accessibility**: ARIA labels and keyboard navigation
- **Internationalization**: Dynamic language switching
- **Visual Feedback**: Smooth animations and transitions

## 🔒 Security Features

- HTTPS encryption for all communications
- Environment variable configuration for sensitive data
- Docker container isolation
- Input validation and sanitization

## 🤝 Contributing

We welcome contributions! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📋 Project Requirements (42 Cursus)

This project fulfills the following 42 requirements:
- ✅ Single Page Application
- ✅ Browser navigation (Back/Forward buttons)
- ✅ Multiple language support
- ✅ Tournament system with brackets
- ✅ Multiple players support
- ✅ AI opponent implementation
- ✅ User management system
- ✅ Responsive design
- ✅ Security implementation
- ✅ Docker containerization

## 🏅 Authors & Contributors

### Core Development Team
- **[Nauman Munir](https://github.com/NomanMunir)** - Frontend Developer, Project Lead
- **[Alaa Bashir](https://github.com/AKhabibr)** - Frontend Developer, Game Logic Specialist
- **[Artur Khabibrakhmanov](https://github.com/AKhabibr)** - Backend Developer
- **[Alex](https://github.com/alex-and-ers)** - Backend Developer

### Contributing
We welcome contributions from the community! Each team member has made significant contributions to different aspects of the project:

- **Backend Services**: User management and tournament APIs
- **Frontend Development**: Game interface and user experience
- **Game Logic**: AI implementation and physics engine
- **Infrastructure**: Docker containerization and deployment

## 📄 License

This project is part of the 42 School curriculum and is intended for educational purposes.

## 🔗 Related Links

- **[Frontend Repository](https://github.com/NomanMunir/ft_transcendence_frontend)** - Standalone frontend implementation
- **[Live Demo](https://nomanmunir.github.io/ft_transcendence_frontend/)** - Play the game online
- **[42 School](https://42.fr/)** - Learn more about 42

---

**Made with ❤️ at 42 School**
