#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
typedef struct Race{
   int numberOfLaps;
   int currentLap;
   char firstPlaceDriverName[20];
   char firstPlaceRaceCarColor[10];

}Race;
typedef struct RaceCar{
    char driverName[20];
    char raceCarColor[20];
    int totalLapTime;
}RaceCar;

// Print functions section
void printIntro(){
    //     
    printf("Bienvenue a notre evenement principal, les fans de course numerique !\n");
    printf("J'espere que tout le monde a pris son gouter car nous allons commencer !\n");

}
void printCountDown(){
    int i;
    printf("Coureurs prets ! Dans...\n");
    for(i=5;i>0;i--){
        printf("%d\n",i);
        sleep(1);
    }

    printf("Course !");
}
int printFirstPlaceAfterLap(Race race){


    printf("Apres le tour numero %d la premiere place est occupee par : %s dans la voiture de course %s !\n",
race.currentLap,race.firstPlaceDriverName,race.firstPlaceRaceCarColor);

}
int printCongratulation(Race race){
    printf("Felicitons tous %s, dans la voiture de course %s, pour son incroyable performance.C'etait vraiment une belle course et bonne nuit a tous !",race.firstPlaceDriverName,race.firstPlaceRaceCarColor);

}
int calculateTimeToCompleteLap(){
    int vitesse;
    int acceleration;
    int nerves;
    time_t t;
    srand((unsigned) time(&t));
    vitesse=rand()%2+1;
    acceleration=rand()%2+1;
    nerves=rand()%2+1;


    return (vitesse+acceleration+nerves);
}
void updateRaceCar(RaceCar *raceCar){
    int i;
    for(i=0;i<5;i++){
       raceCar->totalLapTime=calculateTimeToCompleteLap()+(*raceCar).totalLapTime;

    }
}
void updateFirstPlace(Race *race ,RaceCar *raceCar1 ,RaceCar *raceCar2 ){
    if (raceCar1->totalLapTime >= raceCar2->totalLapTime){
        strcpy(race->firstPlaceDriverName,raceCar1->driverName);
        strcpy(race->firstPlaceRaceCarColor,raceCar2->raceCarColor);

    }
    else{
        strcpy(race->firstPlaceDriverName,raceCar1->driverName);
        strcpy(race->firstPlaceRaceCarColor,raceCar1->raceCarColor);

    }
}
void startRace(RaceCar *raceCar1,RaceCar *courseCar2){

}




main(){
    srand(time(0));

    Race race;
    Race race1={5,2,"hind","rouge"};
    Race race2={5,4,"nouhaila","bleu"};
    // strcpy(race.firstPlaceDriverName,"hind");
    // strcpy(race.firstPlaceRaceCarColor,"rouge");
    race.currentLap=rand()%5;
    

    printIntro();
    printCountDown();
    printFirstPlaceAfterLap(race1);
    printCongratulation(race2);
    printf("resultat set %d",calculateTimeToCompleteLap());
    updateRaceCar(&race1);
    updateRaceCar(&race1);


}