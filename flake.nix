{
  description = "my project description";

  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem
      (system:
        let pkgs = import nixpkgs { system = "${system}"; config.allowUnfree = true; };
            qmkPackages = import ./shell.nix { inherit pkgs; };
            devEnv = if builtins.pathExists ./_devEnv.nix then import ./_devEnv.nix { inherit pkgs; } else {};
            env = pkgs.lib.zipAttrs [qmkPackages devEnv];
        in
        {
          devShells.default = pkgs.mkShell {
            packages = if env ? packages then env.packages else [];
            buildInputs = env.buildInputs;
            DEV_EDITOR = if env ? DEV_EDITOR then env.DEV_EDITOR else "";
          };
        }
      );
}
