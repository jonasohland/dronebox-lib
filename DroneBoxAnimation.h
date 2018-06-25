#ifndef _DroneBoxAnimation_
#define _DroneBoxAnimation_

static int frame = 0;

static inline void anim_fly1(DroneBox *db, bool * playing){
    if(*playing){
        switch(frame){


                case 0:
                    db->setOne(0, 0, 0, 255, 255);
                    break;

                case 1:
                    db->setOne(1, 1, 1, 255, 255);
                    db->setOne(0, 2, 1, 255, 255);
                    db->setOne(2, 0, 1, 255, 255);

                    
                    
                    break;

                case 2:
                    db->setOne(2, 2, 2, 255, 255);
                    db->setOne(0, 4, 2, 255, 255);
                    db->setOne(4, 0, 2, 255, 255);
                    db->setOne(1, 3, 2, 255, 255);
                    db->setOne(3, 1, 2, 255, 255);
                    
                    
                    //db->setOne(2, 2, 2, 255, 255);

                    
                    break;
                case 3:
                    db->setOne(3, 3, 3, 255, 255);
                    db->setOne(2, 4, 3, 255, 255);
                    db->setOne(4, 2, 3, 255, 255);
                    
                    break;
                case 4:
                    db->setOne(4, 4, 4, 255, 255);

                    frame = -1;
                    *playing = 0;
                    break;


            
            


        }
            frame++;
    }
}

static inline void anim_fly2(DroneBox *db, bool * playing){

    if(*playing){
        switch(frame){

            case 0:
                db->setOne(0,0,0, 255,255);
                break;
            case 1:
                db->setOne(1,0,1, 255,255);
                db->setOne(0,1,1, 255,255);
                db->setOne(1,0,0, 255,255);
                db->setOne(0,1,0, 255,255);
                break;
            case 2:
                for(int z = 0; z < 3; z ++){
                    db->setOne(0, 2, z, 255,255);
                    db->setOne(1, 1, z, 255,255);
                    db->setOne(2, 0, z, 255,255);
                }
                break;
            case 3:
                for(int z = 0; z < 4; z ++){
                    db->setOne(0, 3, z, 255,255);
                    db->setOne(3, 0, z, 255,255);

                    db->setOne(1, 2, z, 255,255);

                    db->setOne(2, 1, z, 255,255);
        

                }

                break;
            case 4:
                for(int z = 0; z < 5; z ++){
                    db->setOne(0, 4, z, 255,255);
                    db->setOne(4, 0, z, 255,255);

                    db->setOne(3, 1, z, 255,255);

                    db->setOne(2, 2, z, 255,255);
                    db->setOne(1, 3, z, 255,255);

        

                }
                break;
            case 5:
                for(int z = 1; z < 5; z ++){
                    db->setOne(4, 1, z, 255,255);
                    db->setOne(1, 4, z, 255,255);

                    db->setOne(3, 2, z, 255,255);

                    db->setOne(2, 3, z, 255,255);
        

                }
                break;
            case 6:
                for(int z = 2; z < 5; z ++){
                    db->setOne(3, 3, z, 255,255);
                    db->setOne(4, 2, z, 255,255);
                    db->setOne(2, 4, z, 255,255);
                }
                break;
            case 7:
                for(int z = 3; z < 5; z ++){
                    db->setOne(4, 3, z, 255,255);
                    db->setOne(3, 4, z, 255,255);
                }
                break;



            
            
            case 8:
                db->setOne(4, 4, 4, 255, 255); 
            frame = -1;
            *playing = 0;
            break;
        }
        frame++;
    }

}


static inline void anim_fly3(DroneBox *db, bool * playing){
    if(*playing){
        switch(frame){

            case 0:
                db->setOne(2,2,2,255,255);
                break;
            case 1:
                for(int z = 1; z<3; z++){
                    db->setOne(1,1,z,255,255);
                    db->setOne(1,2,z,255,255);
                    db->setOne(1,3,z,255,255);
                    db->setOne(2,1,z,255,255);
                    db->setOne(3,1,z,255,255);
                    db->setOne(3,2,z,255,255);
                    db->setOne(3,3,z,255,255);
                    db->setOne(2,3,z,255,255);

                }
                break;
            case 2:

                for(int z = 0; z<5; z++){
                    for(int x = 0; x < 5; x++){
                        db->setOne(x, 0, z, 255, 255);
                        db->setOne(x, 4, z, 255, 255);
                    }
                    for(int y = 0; y < 5; y++){
                        db->setOne(0, y, z, 255, 255);
                        db->setOne(4, y, z, 255, 255);
                    }

                }
                
                
                frame = -1;
                *playing = 0;
                break;
        }
        frame++;
    }

}

static inline void anim_fly4(DroneBox *db, bool * playing){
    if(*playing){
        switch(frame){

            case 0:
                db->setOne(2,2,2,255,255);
                break;
            case 1:
                for(int z = 1; z<3; z++){
                    db->setOne(1,1,z,255,255);
                    db->setOne(1,2,z,255,255);
                    db->setOne(1,3,z,255,255);
                    db->setOne(2,1,z,255,255);
                    db->setOne(3,1,z,255,255);
                    db->setOne(3,2,z,255,255);
                    db->setOne(3,3,z,255,255);
                    db->setOne(2,3,z,255,255);

                }
                break;
            case 2:

                for(int z = 0; z<5; z++){
                    for(int x = 0; x < 5; x++){
                        db->setOne(x, 0, z, 255, 255);
                        db->setOne(x, 4, z, 255, 255);
                    }
                    for(int y = 0; y < 5; y++){
                        db->setOne(0, y, z, 255, 255);
                        db->setOne(4, y, z, 255, 255);
                    }

                }
            case 3:
                for(int z = 1; z<3; z++){
                    db->setOne(1,1,z,255,255);
                    db->setOne(1,2,z,255,255);
                    db->setOne(1,3,z,255,255);
                    db->setOne(2,1,z,255,255);
                    db->setOne(3,1,z,255,255);
                    db->setOne(3,2,z,255,255);
                    db->setOne(3,3,z,255,255);
                    db->setOne(2,3,z,255,255);

                }
                break;
            case 4:
                db->setOne(2,2,2,255,255);
                
                
                frame = -1;
                *playing = 0;
                break;
        }
        frame++;
    }

}





static inline void run(DroneBox *db, bool *playing, int * freq, int * spray, int * vol, int * fm, int * pitch){
    if(*playing){
        

        char blue1x = random(5);
        char blue1y = random(5);
        
        

        for(int k = 0; k < *freq;  k++){
            char freqled = random(5);
            db->setOne(2,2,freqled,*vol,0);
            

        }

        for(int k = 0; k < *spray; k++){
            char red1x = random(5);
            char red1y = random(5);
            char red1z = random(5);
            
            db->setOne(red1x, red1y, red1z, *vol, 0);
        }

        for(int k = 0; k < *pitch; k++){
            char bluex = random(5);
            char bluey = random(5);
            char bluez = random(5);

            db->setOne(bluex, bluey, bluez, 0, *vol);
        }


        
        



        
    }
    
}

/*static inline void anim_fly5(DroneBox *db, bool * playing){
    if(*playing){
        switch(frame){
        
            case 0:
               db->setOne(2,2,2, 255, 50);



            case 1:

                frame = -1;
                *playing = 0;
                break;
        }
        frame++;
    }

}*/

static inline void sparkle1(DroneBox * db, bool  * playing, int wide, int base){
    if(*playing)
    {
        for(int i = 0; i< 4; i++){
            int led1x = 2 - random(5);
            int led1y = 2 - random(5);
            int led1z = 2 - random(5);
            db->setOne(2+led1x,2+led1y,2+led1z, wide, wide);
        }

        
        for(int i = 0; i< 15; i++){
            int led2x = 1 - random(3);
            int led2y = 1 - random(3);
            int led2z = 1 - random(3);
            db->setOne(2+led2x,2+led2y,2+led2z, base, base);
        }

        



        frame++;

        if(frame > 255){
            frame = 0;
            *playing = 0;
        }
    }

}


#endif