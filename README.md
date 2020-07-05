# Native ReasonML Remote Containers Example

This repo demonstrates using VSCode Remote Container development for Reason Native.

The example project performs an HTTP request to ipinfo.io and prints your IP to console.

## Build/Run in Container

In VSCode press F1 and search/choose "Remote-Containers: Open Repository in Container..."

Type `shayne/reason-devcontainer`

VSCode will relaunch in a container, install deps and run `esy`. The first launch will take a while to install all deps, including the `jaredly.reason-vscode` VSCode extension.

After dependencies are installed, the container is attached and you can open a terminal and run `esy x getip`.