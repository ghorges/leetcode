#!/bin/bash
echo "\033[46;37m ----------------------------Begin---------------------------- \033[0m"
echo "\033[34m Hi, Curtin. Coding your message. \033[0m"
read -p "Writing message: " commitInfo
echo $commitInfo
str="\""
hw=${str}${commitInfo}${str}
git commit -m "\"\\"${commitInfo}"\\\""
echo "\033[46;37m ----------------------------End---------------------------- \033[0m"
