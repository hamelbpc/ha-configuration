#!/usr/bin/env bash
cd /config
git config core.sshCommand "-o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -i /config/.ssh/id_rsa -F /dev/null"
git add .
git commit -m "changes made in home assistant"
git push origin main
