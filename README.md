# Oiram

## Générer/Configurer la solution :

1. Vcpkg
    1. Installer [vcpkg](https://github.com/microsoft/vcpkg) en clonant le repository
    2. Ajouter le dossier vcpkg a vos variable systèmes  
        - ouvrir l'application "modifier les variables d'environement système"
        - cliquer sur variable d'environement
        - dans variables système cliquer sur path puis sur modifier
        - cliquer sur nouveau et entrée le path jusqu'à votre dossier vcpkg
        - redemarer votre pc
        - ouvrez votre terminal et lancer la commande vcpkg
        
        Vous devriez obtenir ce résultat :
        ```
            PS C:\Users\etien> vcpkg
            usage: vcpkg <command> [--switches] [--options=values] [arguments] @response_file
            @response_file         Contains one argument per line expanded at that location
        ```
2. Repository
    1. Cloner le repository en utilisant la commande suivante:
    ```bash
        git clone https://github.com/Andoradogaris/oiram.git
    ```
    ou telecharger le fichier zip
3. Cmake
    1. Installer [cmake](https://cmake.org/download/)
    2. Lancer le fichier **build.bat** dans le repository
4. Rider
    1. Cliquer sur **ALL_BUILD** a coté du bouton executer
    2. Selectionner oiram

Vous pouvez désormais lancer le projet

## Architecture de projet

[image structure](diagrame.drawio)
