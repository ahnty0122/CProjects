#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct MEMORY{
		int page_num; 
		int reference_bit;
		int dirty_bit;
};
struct PAGE{
		int memory_location;
        int valid_bit; 
};
struct PAGE page[200000];
int main(int argc, char *argv[]){
	int page_fault = 0;
	int disk_write = 0;
	int head_dist = 0;
	int head_pt = 0;
	int pg,op;
	int memory_size = atoi(argv[1]);
	FILE *input_file = fopen("a.txt","r");
	struct MEMORY *memory = (struct MEMORY *) malloc(memory_size * sizeof(struct MEMORY)); 
	struct MEMORY *clock = memory;
	for(int i = 0; i < memory_size; i++){
		memory[i].reference_bit = 0;
		memory[i].dirty_bit = 0;
		memory[i].page_num = 0;
		}
	for(int i = 0; i < 200000; i++) page[i].valid_bit = 0;
	while(!feof(input_file)){
		fscanf(input_file, "%d %d", &pg, &op);
		if(page[pg].valid_bit == 1){
			memory[page[pg].memory_location].reference_bit = 1;
			if(op==1) memory[page[pg].memory_location].dirty_bit = 1;
		 }
		 else{
			page_fault++;
			while(1){
				if(clock->reference_bit ==1)
					clock->reference_bit = 0;
				else{
					page[clock->page_num].valid_bit = 0;
					clock->reference_bit = 0;
					page[pg].valid_bit = 1;
					page[pg].memory_location = clock-memory;
					if(clock->dirty_bit){
						disk_write++;
						head_dist+=abs(head_pt-(clock->page_num)/1000);
						head_dist+=abs(clock->page_num/1000-pg/1000);
					}
					else head_dist+=abs(head_pt-pg/1000);
					head_pt = pg/1000;
					if(op == 1) clock->dirty_bit = 1;
					else clock->dirty_bit = 0;
					clock->page_num = pg;
					clock++;
				if(clock-memory ==memory_size)
					clock = memory;
					break;
				}
				clock++;
				if(clock-memory ==memory_size) clock = memory;
			}
		 }
	}
	printf("%d\n%d\n%d\n",page_fault,disk_write,head_dist);
	return 0;
}