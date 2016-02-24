#Pour installer le plugin dans le projet :

#On nétoie d'abord le projet cible

rm -rf ../gs/src/main/webapp/cordova/platforms/
cd ../gs/src/main/webapp/cordova/
ionic platform add ios
ionic plugin add https://github.com/brodysoft/Cordova-SQLitePlugin
#On installe le plugin
cd -
plugman install --platform ios --project ../gs/src/main/webapp/cordova/platforms/ios/ --plugin .

#On le build 
cd -
ionic build ios
ionic run ios

