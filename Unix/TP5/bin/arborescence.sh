#!/bin/sh
mkdir /Users/bod/Documents/BTS/Unix/TP5/bin
mkdir /Users/bod/Documents/BTS/Unix/TP5/test
cd /Users/bod/Documents/BTS/Unix/TP5/test
echo "entrez le nom des dossiers que vous souhaitez crée :"
read dossier
echo "création du répertoire: `eval echo $dossier`"
mkdir $dossier
read dossier
echo "création du répertoire: `eval echo $dossier`"
mkdir $dossier
read dossier
echo "création du répertoire: `eval echo $dossier`"
mkdir $dossier
cd rep1
read dossier
echo "création du répertoire: `eval echo $dossier`"
mkdir $dossier
cd  rep11
echo "entrez le nom des fichiers que vous souhaitez crée : "
read file
echo "création du fichier: `eval echo $file`"
touch $file
read file
echo "création du fichier: `eval echo $file`"
touch $file
cd ../../rep2
read file
echo "création du fichier: `eval echo $file`"
touch $file
read file
echo "création du fichier: `eval echo $file`"
touch $file
