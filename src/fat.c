#include "sd.h"
#include "fat.h"
#include "rprintf.h"
#include "cFun.h"
#include "serial.h"

struct boot_sector *bs;
char bootSector[512];
//char fat_table[8*SECTOR_SIZE];
unsigned int root_sector;
char iBuffer[512];
struct root_directory_entry *fat;


int fat_init() {

	char buffer[10];

	sd_readblock(0,(unsigned char*) bootSector, 1);
	bs = (struct boot_sector*) bootSector;
	int i = 1;
	while  (bs->fs_type[i] != ' '){
		esp_printf(putc, "%c", bs->fs_type[i]);
		buffer[i] = bs->fs_type[i];
		i++;
		buffer[i] = 0;

	}

								// Validate the boot signature = 0xaa55
	if (bs->boot_signature = 0xaa55) {
		esp_printf(putc, "Validated boot signiture \n");
	}
								// Validate fs_type = "FAT12" using strcmp
	if (strcmp(buffer, "FAT16")) {
		esp_printf(putc, "It is a FAT16 \n \n");
	}

								// Print out some of the elements of the BIOS information block using rprintf...
	esp_printf(putc, "Bytes per sector = %d \n" ,bs->bytes_per_sector);
	esp_printf(putc,"Sectors per cluster--> %d\n" ,bs->num_sectors_per_cluster);
	esp_printf(putc,"Root Directory entries--> %d\n" ,bs->num_root_dir_entries);

	// Read FAT table from the SD card into array fat_table
	//  Compute root_sector as:
	// num_fat_tables + num_sectors_per_fat + num_reserved_sectors + num_hidden_sectors
}




void fat_open(struct file* file, char* filename) {
	int t_sectors = bs->num_root_dir_entries;
	int t = 1;
	char buffer[10];

	int root_sector_value = (bs->num_fat_tables * bs-> num_sectors_per_fat) + bs->num_hidden_sectors + bs->num_reserved_sectors;
	esp_printf(putc,  "BOOT SECTOR = %x\n", bs);
	sd_readblock(root_sector_value, iBuffer, 1);
	fat = iBuffer;
	while(t < t_sectors ) {
	int k = 0;
	while (k < 8){
		esp_printf(putc, "%c", fat->file_name[k]);
		if(fat -> file_name[k] != ' ')
			buffer[k] = fat->file_name[k];
		k++;
	}
	buffer[7] = 0;
	if (strcmp(buffer, filename) == 0){
		esp_printf(putc, "Buffer is equal \n");
		file->rde = *fat;
		file->start_cluster = fat->cluster;
		return;
		}
		esp_printf(putc, "\n%s\n", buffer);
		t++;
		fat++;
	}

}

void fat_read(struct file* file, char buffer) {

	esp_printf(putc, "\nRDE Cluster --> %d \n", file->rde.cluster);

	int first_root_dir = bs->num_reserved_sectors + (bs->num_fat_tables * bs->num_sectors_per_fat) + ((bs->num_root_dir_entries * 32) + (bs->bytes_per_sector - 1)) / bs->bytes_per_sector;
	int first_sector = first_root_dir + ((file->rde.cluster - 2) * bs->num_sectors_per_cluster);

	sd_readblock(first_sector,iBuffer,1);

	esp_printf(putc, "Readblock --> %s\n", iBuffer);
	esp_printf(putc, "First root dir --> %d\n", first_root_dir);
	esp_printf(putc, "First sector --> %d\n", first_sector);

}
