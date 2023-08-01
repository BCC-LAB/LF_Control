float ConvertDeg(float x ,float y){
    float degree;

    if(x>0){
        degree = 90-(atan(y/x)*180/3.14);
    }
    if(x<0 && y>0){
        degree = abs(atan(y/x)*180/3.14) + 270;
    }
    if(x<0 && y<0){
        degree = (atan(x/y)*180/3.14) + 180;
    }
    if(x==0 && y>=0){
        degree = 0;
    } 
    if(x==0 && y<0){
        degree = 180;
    }if(x>0 && y==0){
        degree = 90;
    }if(x<0 && y==0){
        degree = 270;
    }

    return degree;
}

float check_direction(float error_degree){
    
    int direction;
    if(error_degree <= 180 && error_degree >= 0){              //check yaw direction
        direction = -1;
    }else if(error_degree < -180 && error_degree < 0){
        direction = -1;
    }else if(error_degree >= -180 && error_degree < 0){
        direction = 1;
    }else if(error_degree > 180 && error_degree >= 0){
        direction = 1;
    }

    return direction;
}
