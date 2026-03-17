# Axiom - Geometry Dash Hack Client

<img src="resources\AxiomLogo.ico" width="150" alt="Axiom Logo" />

A powerful hack client for Geometry Dash built with the Geode SDK and VSCode.

## 🎮 Features

### Core Hacks
- **Noclip** - Pass through all obstacles without dying
- **Speed Hack** - Adjust game speed from 0.0001x to 100x
- **Instant Complete** - Automatically complete levels
- **FPS Bypass** - Unlock frame rates up to 520 FPS
- **Practice Music Fix** - Fixes music synchronization in practice mode

### Settings
All features are configurable through the in-game mod settings:
- Toggle features on/off individually
- Adjust speed multiplier with precision
- Set custom target FPS (60-360)

## 🚀 Installation

1. Make sure you have [Geode](https://geode-sdk.org/) installed
2. Download the latest release of Axiom
3. Place the `.geode` file in your Geometry Dash mods folder
4. Launch Geometry Dash and enable the mod

## 🛠️ Building from Source

### Prerequisites
- [Geode CLI](https://github.com/geode-sdk/cli)
- CMake 3.21 or higher
- C++23 compatible compiler

### Build Instructions
```sh
# Clone the repository
git clone https://github.com/M1tchn3r-GD/Axiom
cd axiom

# Build with Geode CLI
geode build

# Install to your GD mods folder (optional)
geode install
```

For more detailed build instructions, see the [Geode documentation](https://docs.geode-sdk.org/getting-started/create-mod#build).

## 📖 Usage

### Accessing Axiom
1. Launch Geometry Dash
2. Click the Axiom button on the main menu (bottom toolbar)
3. Configure your desired settings

### Feature Guide

#### Noclip
Enable noclip to pass through all obstacles. Your player will not die from collisions.
- **Default**: Off
- **Use Case**: Testing levels, exploring layouts

#### Speed Hack
Adjust the game speed multiplier for slow-motion or fast-forward gameplay.
- **Default**: 1.0x (normal speed)
- **Range**: 0.0001x - 100x
- **Use Case**: Practice difficult sections, speedrun testing

#### Instant Complete
Automatically completes levels when enabled. Useful for unlocking progression.
- **Default**: Off
- **Warning**: May affect statistics

#### FPS Bypass
Unlocks frame rate limits for smoother gameplay on high-refresh-rate monitors.
- **Default**: Off
- **Target FPS**: 60-360
- **Recommended**: 240 FPS for most systems

#### Practice Music Fix
Fixes music desync issues in practice mode by continuously syncing audio with game state.
- **Default**: Off
- **Use Case**: Better practice mode experience

## ⚙️ Configuration

Settings are stored in `mod.json` and can be adjusted in-game:

```json
{
  "speed-hack": 1.0,
  "noclip": false,
  "instant-complete": false,
  "practice-music-fix": false,
  "fps-bypass": false,
  "target-fps": 240
}
```

## 🔧 Development

### Project Structure
```
axiom/
├── src/
│   └── main.cpp          # Main mod implementation
├── resources/
│   └── logo.png          # Mod icon
├── mod.json              # Mod configuration
├── CMakeLists.txt        # Build configuration
├── README.md
├── changelog.md
└── about.md
```

### Key Components

**Noclip Implementation** (`PlayerObject` hooks)
- Prevents death on collision
- Bypasses anti-cheat jump counters

**Speed Hack** (`CCScheduler` hook)
- Modifies delta time for all game updates
- Smooth speed adjustment

**Instant Complete** (`PlayLayer` hook)
- Triggers level completion animation
- Schedules completion after 0.1s

**FPS Bypass** (`PlayLayer::update` hook)
- Subdivides frame updates
- Maintains physics accuracy

**Practice Music Fix** (`FMODAudioEngine` hook)
- Syncs audio position with game state
- Continuous update loop

## 🤝 Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues.

### Development Guidelines
1. Follow Geode SDK best practices
2. Test all features on multiple platforms
3. Update changelog for new features
4. Keep code well-commented

## 📝 Changelog

See [changelog.md](changelog.md) for version history.

## ⚠️ Disclaimer

This mod is for educational and testing purposes. Use at your own risk. Hacking in online levels or competitive scenarios is bad. I do NOT want to hear someone complaining because their account got banned.

## 🔗 Resources

- [Geode SDK Documentation](https://docs.geode-sdk.org/)
- [Geode SDK Source](https://github.com/geode-sdk/geode/)
- [Geode CLI](https://github.com/geode-sdk/cli)
- [GD Bindings](https://github.com/geode-sdk/bindings/)

## 📄 License

This project uses the Geode SDK, which is licensed under the Boost Software License 1.0.

## 👤 Author

**M1tchn3r**

---

*Built with ❤️ using Geode SDK and VSCode*
    *And M1tchn3r. Don't forget me*
        *| unimportant guy |*

            *Why are you still here*



            
                **STOP**