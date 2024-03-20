#!/bin/bash

# Demander le message de commit
read -p "Enter commit message: " commit_message

# Construire la commande avec le message de commit fourni
command="git add . && git commit -m "$commit_message" && git push && git status"

# Afficher la commande
echo "Command to execute: $command"

# Demander confirmation avant d'exécuter
read -p "Execute this command? (y/n): " execute
if [[ $execute == "y" ]]; then
    # Exécuter la commande
    eval "$command"
else
    echo "Command execution aborted."
fi
