#!/bin/bash

git pull
git add *
git commit -m "$(date '+%Y-%m-%d')"
git push

