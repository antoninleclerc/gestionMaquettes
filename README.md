# Qualité de programmation - Gestion des maquettes

## Aide à l'utilisation de Git ##
### Branches ###
Rappel des différentes branches ainsi que leur utilité :
* <b>master</b> : On y ajoute que le code déjà fonctionnel et testé de la branche <b>dev</b>. Le code doit :
  * Compiler ;
  * Non buggé ;
  * Commenté.
* <b>dev</b> : On retrouve le code en développement. C'est ici que la majorité du travail se situe. On travaille dans cette branche.

### Git et Visual Studio 2017 ###
#### Début ####
Pour récuperer le projet une première fois sur Visual Studio 2017, rendez vous dans l'onglet <b>Team Explorer</b> en bas du panneau de gauche sur Visual Studio, cliquez sur <b>Cloner</b>, et saisissez l'URL suivante pour le dépôt : https://github.com/antoninleclerc/gestionMaquettes.git <br>
Retournez ensuite dans l'onglet <b>Team Explorer</b> puis double-cliquez sur le nom du dépôt (gestionMaquettes), cliquez sur <b>Branches</b>, déroulez <b>remotes/origin</b> et double-cliquez sur <b>dev</b>.<br>
Finalement, cliquez sur la maison dans le panneau de <b>Team Explorer</b>, puis double-cliquez sur <b>gestionMaquettes</b> sous la catégorie <b>Solutions</b>.

#### Modifications ####
Une fois vos modifications réalisés, il faut les envoyer sur le Git. Allez dans le <b>Team Explorer</b>. Ici, en cliquant droit sur les différents fichiers que vous avez modifié, vous pouvez soit le comparer avec l'ancien, soit annuler la modification que vous avez apporté depuis le dernier Fetch.<br><br>

Une fois vos modifications terminés, vous devez entrer un message, puis appuyer sur "Valider tout".

#### Envoi sur le Git ####
Après avoir Commit vos modifications, il vous suffit de vous rendre dans la catégorie <b>Synchroniser</b> de <b>Team Explorer</b>, puis cliquer sur <b>Synchroniser</b>. <br>
<b>Vérifiez bien que vous soyez sur la branche "dev" avant de synchroniser, le master est uniquement modifiable via les <b>Pull Requests</b>.

#### Réceptionner la dernière mise à jour ####
Allez dans la catégorie <b>Synchroniser</b>, puis cliquez sur <b>Tirer</b>.
