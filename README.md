# Coding Battle 2018 – Shaker

Voici les problèmes de la phase d'entraînement de la Coding Battle. Ceux-ci ont été imaginés et écrits par INSAlgo.

Les problèmes couverts étaient assez divers :

* **Coding Battle – Échauffement**
    - **A. 42**, qui consistait à trouver la réponse à la question sur la Vie, l'Univers et le Reste.
    - **B. The Alchemist**, qui consistait à trouver le nombre de moyens de fabriquer une pierre philosophale.
    - **C. Riddle**, qui consistait à trouver le n ème terme d'une suite un peu particulière.

Les solutions disponibles sont celles que nous avons écrites. Il y a souvent de nombreux moyens de résoudre un problème, nos solutions ne sont donc que des propositions.

## Comment tester avec les entrées / sorties fournies

La plateforme de la Coding Battle ne sera pas relancée. Cela est dû à plusieurs raisons : nous sommes une association étudiante dont l'organisation de concours n'est pas le motif principal et cela demanderait trop de temps ; pour des raisons de coûts, une telle infrastructure a un prix ; parce que vous n'en avez pas besoin ! 😉

Pour tester vos solutions, vous pouvez utiliser la redirection de flux dans un terminal. Par exemple, sous Linux (sous Windows la syntaxe est similaire, et l'Internet foisonne de tutoriels et de posts de forum à ce propos) :

```Shell
# Python
python solution.py < ../input/input0.txt

# C++
./sol < ../input/input0.txt

# JavaScript
js sol.js < ../input/input0.txt

# etc
```

## Conseils généraux

Nous avons eu l'occasion de lire pas mal de vos soumissions, et nous avons reçu beaucoup de questions durant le concours. Voici quelques conseils en vrac, si vous désirez vous améliorer pour la prochaine édition :

* Apprenez à manipuler les entrées / sorties. En effet, tout problème de programmation compétitive ont cela en commun, et bien souvent les entrées / sorties sont les mêmes (récupérer des entiers, des listes de nombres, des chaînes de caractères,…).
* Servez-vous de la bibliothèque standard de votre langage ! En effet, les langages de programmations ne viennent jamais nus. Par exemple, Python possède dans sa bibliothèque standard une fonction `median()` dans le module *statistics*, et tous les langages possèdent des fonctions de tri sur leurs structures de données.
* Lisez attentivement les énoncés des problèmes !

## License

Le contenu de ce dépôt est publié sous license GPL v3.0. Toute contribution par pull request est bien évidemment la bienvenue !

