#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "transport.dat"
#define MAX_NAME_LEN 100
#define MAX_TYPE_LEN 50
#define MAX_DRIVER_LEN 100
#define MAX_CONTACT_LEN 50

// ------------------ STRUCT DEFINITION ------------------
typedef struct {
    int vehicleID;
    char vehicleName[MAX_NAME_LEN];
    char type[MAX_TYPE_LEN];
    int capacity;
    char driverName[MAX_DRIVER_LEN];
    char driverContact[MAX_CONTACT_LEN];
} Vehicle;

// ------------------ FUNCTION DECLARATIONS ------------------
void addVehicle();
void viewVehicles();
void searchVehicle();
void updateVehicle();
void deleteVehicle();
int idExists(int id);
void saveVehicle(Vehicle v);
void loadVehicles(Vehicle vehicles[], int *count);
void writeAllVehicles(Vehicle vehicles[], int count);

// ------------------ MAIN MENU ------------------
int main() {
    int choice;
    do {
        printf("\n===============================\n");
        printf("   TRANSPORT MANAGEMENT SYSTEM\n");
        printf("===============================\n");
        printf("1. Add New Vehicle\n");
        printf("2. View All Vehicles\n");
        printf("3. Search Vehicle\n");
        printf("4. Update Vehicle\n");
        printf("5. Delete Vehicle\n");
        printf("6. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: viewVehicles(); break;
            case 3: searchVehicle(); break;
            case 4: updateVehicle(); break;
            case 5: deleteVehicle(); break;
            case 6: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// ------------------ ADD VEHICLE ------------------
void addVehicle() {
    Vehicle v;

    printf("\n--- Add New Vehicle ---\n");
    printf("Enter Vehicle ID: ");
    scanf("%d", &v.vehicleID);
    getchar();

    if (idExists(v.vehicleID)) {
        printf("Error: Vehicle ID already exists!\n");
        return;
    }

    printf("Enter Vehicle Name: ");
    fgets(v.vehicleName, sizeof(v.vehicleName), stdin);
    v.vehicleName[strcspn(v.vehicleName, "\n")] = '\0';

    printf("Enter Vehicle Type (Bus/Van/Truck etc): ");
    fgets(v.type, sizeof(v.type), stdin);
    v.type[strcspn(v.type, "\n")] = '\0';

    printf("Enter Capacity: ");
    scanf("%d", &v.capacity);
    getchar();

    printf("Enter Driver Name: ");
    fgets(v.driverName, sizeof(v.driverName), stdin);
    v.driverName[strcspn(v.driverName, "\n")] = '\0';

    printf("Enter Driver Contact: ");
    fgets(v.driverContact, sizeof(v.driverContact), stdin);
    v.driverContact[strcspn(v.driverContact, "\n")] = '\0';

    saveVehicle(v);
    printf("Vehicle added successfully!\n");
}

// ------------------ SAVE VEHICLE TO FILE ------------------
void saveVehicle(Vehicle v) {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(&v, sizeof(Vehicle), 1, fp);
    fclose(fp);
}

// ------------------ CHECK IF ID EXISTS ------------------
int idExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Vehicle v;
    while (fread(&v, sizeof(Vehicle), 1, fp)) {
        if (v.vehicleID == id) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

// ------------------ VIEW ALL VEHICLES ------------------
void viewVehicles() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("\nNo vehicle records found.\n");
        return;
    }

    Vehicle v;
    printf("\n%-10s %-20s %-15s %-10s %-20s %-15s\n",
           "ID", "Name", "Type", "Capacity", "Driver Name", "Contact");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(&v, sizeof(Vehicle), 1, fp)) {
        printf("%-10d %-20s %-15s %-10d %-20s %-15s\n",
               v.vehicleID, v.vehicleName, v.type, v.capacity,
               v.driverName, v.driverContact);
    }

    fclose(fp);
}

// ------------------ SEARCH VEHICLE ------------------
void searchVehicle() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("\nNo records found.\n");
        return;
    }

    int id, found = 0;
    Vehicle v;

    printf("\nEnter Vehicle ID to search: ");
    scanf("%d", &id);

    while (fread(&v, sizeof(Vehicle), 1, fp)) {
        if (v.vehicleID == id) {
            printf("\nVehicle Found:\n");
            printf("ID: %d\nName: %s\nType: %s\nCapacity: %d\nDriver: %s\nContact: %s\n",
                   v.vehicleID, v.vehicleName, v.type,
                   v.capacity, v.driverName, v.driverContact);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No vehicle found with ID %d.\n", id);

    fclose(fp);
}

// ------------------ UPDATE VEHICLE ------------------
void updateVehicle() {
    Vehicle vehicles[200];
    int count = 0, id, found = 0;

    loadVehicles(vehicles, &count);

    printf("\nEnter Vehicle ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (vehicles[i].vehicleID == id) {
            found = 1;
            printf("Enter new driver name: ");
            fgets(vehicles[i].driverName, sizeof(vehicles[i].driverName), stdin);
            vehicles[i].driverName[strcspn(vehicles[i].driverName, "\n")] = '\0';

            printf("Enter new contact: ");
            fgets(vehicles[i].driverContact, sizeof(vehicles[i].driverContact), stdin);
            vehicles[i].driverContact[strcspn(vehicles[i].driverContact, "\n")] = '\0';

            printf("Enter new capacity: ");
            scanf("%d", &vehicles[i].capacity);
            getchar();

            printf("Enter new type: ");
            fgets(vehicles[i].type, sizeof(vehicles[i].type), stdin);
            vehicles[i].type[strcspn(vehicles[i].type, "\n")] = '\0';

            break;
        }
    }

    if (found) {
        writeAllVehicles(vehicles, count);
        printf("Vehicle record updated successfully.\n");
    } else {
        printf("Vehicle ID not found.\n");
    }
}

// ------------------ DELETE VEHICLE ------------------
void deleteVehicle() {
    Vehicle vehicles[200];
    int count = 0, id, found = 0;

    loadVehicles(vehicles, &count);

    printf("\nEnter Vehicle ID to delete: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (vehicles[i].vehicleID == id) {
            found = 1;

            printf("Are you sure you want to delete %s (ID %d)? (y/n): ",
                   vehicles[i].vehicleName, id);
            char confirm = getchar();
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < count - 1; j++)
                    vehicles[j] = vehicles[j + 1];
                count--;

                writeAllVehicles(vehicles, count);
                printf("Record deleted successfully.\n");
            } else {
                printf("Deletion cancelled.\n");
            }

            break;
        }
    }

    if (!found)
        printf("Vehicle ID not found.\n");
}

// ------------------ LOAD & WRITE ALL VEHICLES ------------------
void loadVehicles(Vehicle vehicles[], int *count) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return;

    *count = 0;
    while (fread(&vehicles[*count], sizeof(Vehicle), 1, fp))
        (*count)++;

    fclose(fp);
}

void writeAllVehicles(Vehicle vehicles[], int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(vehicles, sizeof(Vehicle), count, fp);
    fclose(fp);
}
