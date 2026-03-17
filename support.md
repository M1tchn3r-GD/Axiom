# Axiom Support

## 🆘 Getting Help

If you're experiencing issues with Axiom, this guide will help you troubleshoot and find solutions.

## 📋 Table of Contents
1. [Common Issues](#common-issues)
2. [Installation Problems](#installation-problems)
3. [Feature-Specific Issues](#feature-specific-issues)
4. [Performance Issues](#performance-issues)
5. [Reporting Bugs](#reporting-bugs)
6. [FAQ](#faq)

---

## Common Issues

### Mod Won't Load
**Symptoms**: Axiom doesn't appear in mod list or won't enable

**Solutions**:
1. Ensure Geode is properly installed and updated
2. Check that you have the correct GD version (2.2081)
3. Verify the `.geode` file is in the correct mods folder
4. Try reinstalling both Geode and Axiom
5. Check Geode logs for error messages

### Settings Not Saving
**Symptoms**: Settings reset after restarting the game

**Solutions**:
1. Make sure Geode has write permissions
2. Check that `mod.json` isn't set to read-only
3. Try deleting config and letting it regenerate
4. Update to the latest Axiom version

### Game Crashes
**Symptoms**: Game crashes when using certain features

**Solutions**:
1. Disable all features and enable them one by one
2. Check if other mods are conflicting
3. Update graphics drivers
4. Lower FPS bypass target if using FPS bypass
5. Report crash with logs to GitHub Issues

---

## Installation Problems

### "Geode Not Found" Error
1. Download Geode from [geode-sdk.org](https://geode-sdk.org/)
2. Install Geode launcher
3. Run Geode installer for your platform
4. Restart Geometry Dash

### Wrong GD Version
Axiom requires GD 2.2081. To check your version:
1. Open Geometry Dash
2. Check version number in bottom right
3. Update GD if needed through Steam/App Store/Google Play

### Mod File Issues
**File Location**:
- **Windows**: `%LocalAppData%/GeometryDash/geode/mods/`
- **macOS**: `~/Library/Application Support/GeometryDash/geode/mods/`
- **iOS**: Via Geode app interface
- **Android**: `/storage/emulated/0/Android/data/com.robtopx.geometryjump/files/geode/mods/`

---

## Feature-Specific Issues

### Noclip

**Issue**: Noclip not working
- Make sure noclip is enabled in settings
- Check that you're in a playable level (not editor)
- Try restarting the level

**Issue**: Game still counts deaths
- This is intentional - noclip prevents death but statistics may still track attempts

### Speed Hack

**Issue**: Speed hack stutters
- Lower the speed multiplier
- Close other applications
- Disable FPS bypass if both are enabled

**Issue**: Music desync at high speeds
- Enable "Practice Music Fix" in settings
- Speed values above 5x may cause unavoidable desync

### Instant Complete

**Issue**: Level doesn't complete
- Make sure instant complete is enabled BEFORE starting level
- Some custom levels may not trigger properly
- Try disabling and re-enabling the feature

**Issue**: Doesn't work in practice mode
- Instant complete is designed for normal mode
- Use it to skip levels, then practice normally

### FPS Bypass

**Issue**: Low FPS despite bypass
- Increase target FPS in settings
- Check hardware limitations (GPU/CPU)
- Disable V-Sync in game settings
- Close background applications

**Issue**: Physics feel weird
- This is normal at very high FPS (300+)
- Try 144 or 240 FPS for best balance
- Lower FPS if objects behave strangely

### Practice Music Fix

**Issue**: Music still desyncs
- Only works in practice mode
- May not work perfectly with all songs
- Try toggling the feature off and on

---

## Performance Issues

### Low FPS
1. Lower target FPS in FPS bypass settings
2. Disable speed hack
3. Close other mods temporarily
4. Update graphics drivers
5. Lower in-game graphics settings

### High RAM Usage
1. Restart Geometry Dash periodically
2. Close other applications
3. Disable unused Geode mods
4. Check for memory leaks (report if consistent)

### Audio Crackling
1. Disable practice music fix
2. Lower speed hack multiplier
3. Update audio drivers
4. Check Windows audio settings (if on Windows)

---

## Reporting Bugs

### Before Reporting
1. ✅ Update to latest Axiom version
2. ✅ Update Geode to latest version
3. ✅ Test with other mods disabled
4. ✅ Check existing GitHub issues
5. ✅ Collect relevant logs

### What to Include
```
**Bug Description**
Clear description of the issue

**Steps to Reproduce**
1. Step one
2. Step two
3. etc.

**Expected Behavior**
What should happen

**Actual Behavior**
What actually happens

**System Info**
- OS: Windows 11 / macOS 14 / etc.
- GD Version: 2.2081
- Geode Version: 4.0.0
- Axiom Version: 1.0.0
- Other Mods: List installed mods

**Logs**
[Attach Geode log file]

**Screenshots/Videos**
[If applicable]
```

### Where to Report
- **GitHub Issues**: For bugs and technical problems
- **GitHub Discussions**: For feature requests and questions
- **Geode Discord**: For general help and community support

---

## FAQ

### Is Axiom safe to use?
Yes! Axiom only modifies your local game client and doesn't interact with servers or other players' games.

### Will I get banned?
Axiom doesn't connect to online services. However, using hacks to fake online records is against community guidelines.

### Does it work with other mods?
Generally yes! Axiom is designed to be compatible. If you find conflicts, report them.

### Can I use it in the editor?
Some features (like speed hack) work in the editor. Others are level-specific.

### How do I uninstall?
1. Open Geode mod menu
2. Find Axiom in the list
3. Click "Disable" or "Delete"
4. Restart GD

### Is it open source?
Yes! Check out the code on GitHub to see how it works or contribute.

### Can I request features?
Absolutely! Open a GitHub Discussion with your idea.

### Why isn't feature X working on mobile?
Some features may have platform-specific limitations. Check the README for platform compatibility.

---

## 🔗 Additional Resources

- [Geode Documentation](https://docs.geode-sdk.org/)
- [Geode Discord](https://discord.gg/geode)
- [GitHub Repository](https://github.com/yourusername/axiom)
- [Video Tutorials](https://youtube.com/...)

---

## 💬 Community Support

Join the Geode Discord server for:
- Real-time help
- Community discussions  
- Feature suggestions
- Development updates

---

**Still having issues?** Open a GitHub Issue with details and we'll help you out!

*Last Updated: Version 1.0.0*