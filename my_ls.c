// try hack me website to learn cyber security
// sudo  apt  || haudi ho -- python lesson
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>
#include <dirent.h>

typedef struct list{
    char* name_files;
    struct stat st;
    struct list* next;
}node;
 

int my_length(char* str_first){  
   int i ;
   for(i = 0 ; str_first[i] ; i++);
   return i;
}

int strcmp_my(char* fir_str, char* sec_str){
   for(int i = 0; fir_str[i]; i++){
       if(fir_str[i] > sec_str[i])  return fir_str[i] - sec_str[i];
       if(fir_str[i] < sec_str[i])  return fir_str[i] - sec_str[i];
   }
   if(my_length(fir_str) < my_length(sec_str)) return -1;
   else if(my_length(fir_str) < my_length(sec_str)) return 1;


   return 0;
}

void printer(node* names, char fl){
    while(names != NULL){
        if(fl == 'n' || fl == 't'){
            if(names->name_files[0] != '.'){
                printf("%s\n", names->name_files);
            }
        }
        else{
            printf("%s\n", names->name_files);
        }
        names = names->next;
    }
}

node* addlat_past(node* main, char* name,struct stat status){
    node* return_value = (node*)malloc(sizeof(node)), *nodem = (node*)malloc(sizeof(node));
    nodem = main;
    return_value->name_files = name;
    return_value->st = status;
    return_value->next = NULL;
    if(main == NULL){
        main = return_value;
        nodem = main;
    } 
    else{
        for(;main->next != NULL; main = main->next);
        main->next = return_value;
    }
    return nodem;
}

void flag_n(node* names){
   for(; names != NULL; names = names->next){
       if(names->name_files[0] != '.') {
           printf("%s\n", names->name_files);
       }
   }
}

void flag_time(node* callout){
    node* named = callout;
    node* copy = callout;
    node* temp = (node*)malloc(sizeof(node));
    for(;callout->next != NULL; callout = callout->next){
            struct stat fs;
            stat(callout->name_files, &fs);
            named = callout->next;
            for(;named != NULL;named = named->next){
                struct stat fsec;
                stat(named->name_files , &fsec);
                if(fs.st_mtim.tv_sec <= fsec.st_mtim.tv_sec){
                    if(fs.st_mtim.tv_nsec < fsec.st_mtim.tv_nsec){
                        temp->name_files = callout->name_files;
                        temp->st = fs;
                        callout->name_files = named->name_files;
                        fs = fsec;
                        named->name_files = temp->name_files;
                        fsec = temp->st;
                    }
                    else{
                        temp->name_files = callout->name_files;
                        temp->st = fs;
                        callout->name_files = named->name_files;
                        fs = fsec;
                        named->name_files = temp->name_files;
                        fsec = temp->st;   
                    }
                }
            }
}
    printer(copy, 't');
}

void flag_x(node* callout){
       node* named = callout;
    node* copy = callout;
    node* temp = (node*)malloc(sizeof(node));
    for(;callout->next != NULL; callout = callout->next){
            struct stat fs;
            stat(callout->name_files, &fs);
            named = callout->next;
            for(;named != NULL;named = named->next){
                struct stat fsec;
                stat(named->name_files , &fsec);
                if(fs.st_mtim.tv_sec <= fsec.st_mtim.tv_sec){
                    if(fs.st_mtim.tv_nsec < fsec.st_mtim.tv_nsec){
                        temp->name_files = callout->name_files;
                        temp->st = fs;
                        callout->name_files = named->name_files;
                        fs = fsec;
                        named->name_files = temp->name_files;
                        fsec = temp->st;
                    }
                    else{
                        temp->name_files = callout->name_files;
                        temp->st = fs;
                        callout->name_files = named->name_files;
                        fs = fsec;
                        named->name_files = temp->name_files;
                        fsec = temp->st;   
                    }
                }
            }
} 
printer(copy, 'x');
}

void flag_a(node* name){
    printer(name, 'a');
}

void flag_influence_sort(char flag, node* names_here){
    node* sorted = (node*)malloc(sizeof(node));  
    if(flag == 'a') flag_a(names_here);
    else if( flag == 'n') flag_n(names_here);
    else if(flag == 't') flag_time(names_here);
    else if(flag == 'x') flag_x(names_here);
}

node* sorting_names_here(node* p1){
   node* head= p1;
   node* next= p1;
   char* temp;
    while (head->next!=NULL) {
       next=head->next;
       while (next!= NULL){
       if(strcmp_my(head->name_files , next->name_files) > 0)
       {
           temp= head->name_files;
           head->name_files= next->name_files;
           next->name_files= temp;
       }
        
       else{
           next=next->next;
           }
       }
       head=head->next;


   } 
   return p1;     
}

void open_whole_folder(char flag){

    DIR* directory;
    struct dirent* entities;
    node* nodes = (node*)malloc(sizeof(node));
    nodes = NULL;
    directory = opendir(".");
    struct stat fd_file;
    while((entities = readdir(directory))){
        stat(entities->d_name, &fd_file);
        nodes = addlat_past(nodes, entities->d_name, fd_file);
    }
    
    nodes = sorting_names_here(nodes);
    flag_influence_sort(flag, nodes);

}

node* open_dir(char* dir, char fl){
    node* take_name = (node*)malloc(sizeof(node));
    take_name = NULL;
    DIR* direct;
    struct dirent* enty;
    direct = opendir(dir);
    struct stat fd_file;
    while((enty = readdir(direct))){
        stat(enty->d_name, &fd_file);
        take_name = addlat_past(take_name, enty->d_name, fd_file);
    }
    return take_name;
}   
void each_file_or(char* file_dir, char flag){
    int fd = open(file_dir, O_RDONLY);
    struct stat st;
    node* dir_name = (node*)malloc(sizeof(node));
    stat(file_dir, &st);
    if(fd > 0){
        if(S_ISDIR(st.st_mode) > 0){
            dir_name = open_dir(file_dir, flag);
            printf("\n%s:\n", file_dir);
            dir_name = sorting_names_here(dir_name);
            flag_influence_sort(flag, dir_name);
        }
        else{
            printf("%s\n", file_dir);
        }
    }
    else{
        printf("ls: cannot access '%s': No such file or directory\n", file_dir);
    }
}

void open_dires(char flag , node* name){
    name = sorting_names_here(name);
    node* companion = name;
    for(;companion != NULL; companion = companion ->next){
       each_file_or(companion->name_files, flag);
    }
}

void work_with_flag(char flag, node* name){
    if(name == NULL) open_whole_folder(flag);
    else open_dires(flag, name);
}

void main_ls_here(int asize, char** ways){
    int a  = 0, b = 0, x = 0;
    struct stat status;
    node* here_names = (node*)malloc(sizeof(node));
    here_names = NULL;
    char flag = 'n';
    for(int y = 1; y < asize; y++){
        if(strcmp(ways[y], "-at") == 0 || strcmp(ways[y], "-ta") == 0 ) x = 1;
        else if(strcmp(ways[y], "-a") == 0 ) a = 1;
        else if(strcmp(ways[y], "-t") == 0 ) b = 1;
        else{
            stat(ways[y],&status);
            here_names = addlat_past(here_names, ways[y],status);
        }
    }
    if(x == 1 || (a == 1 && b == 1)) flag = 'x';
    else if(a == 1) flag = 'a';
    else if(b == 1) flag = 't';
    work_with_flag(flag, here_names);
}

int main(int ac, char** av){
    main_ls_here(ac, av);
}
