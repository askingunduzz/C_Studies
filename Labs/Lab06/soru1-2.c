#include <stdio.h>
#include <string.h>
#define MAX_SHAPES 50

typedef struct {
    double x;
    double y;
    double z;
} point_t;

typedef struct {
    point_t center;
    double radius;
} sphere_t;

typedef struct {
    point_t center;
    double side;
} cube_t;

typedef struct {
    point_t center;
    double base_side;
    double height;
} square_prism_t;

typedef union {
    cube_t cube;
    square_prism_t square_prism;
    sphere_t sphere;
} shape3d_data_t;

typedef enum {
    CUBE,
    SQUARE_PRISM,
    SPHERE
} class_t;

typedef struct {
    class_t type;
    shape3d_data_t shape;
} shape_t;


int scanShape(FILE *filep, shape_t *objp) {
    char shape_ty[40];
    int read_c;
    read_c= fscanf(filep, "%s", shape_ty);

    if (read_c == EOF) {
        return 0; }
    int y =0;
if (strcmp(shape_ty, "cube") == y) {
        objp->type = CUBE;
        read_c = fscanf(filep, "%lf %lf %lf %lf",
      &objp->shape.cube.center.x, &objp->shape.cube.center.y, &objp->shape.cube.center.z, &objp->shape.cube.side);
        return (read_c == 4); } 
        else if (strcmp(shape_ty, "square_prism") == y) {
        objp->type = SQUARE_PRISM;
        read_c = fscanf(filep, "%lf %lf %lf %lf %lf",
        &objp->shape.square_prism.center.x, &objp->shape.square_prism.center.y, &objp->shape.square_prism.center.z, &objp->shape.square_prism.base_side, &objp->shape.square_prism.height);
        return (read_c == 5);}
        else if (strcmp(shape_ty, "sphere") == y) {
        objp->type = SPHERE;
        read_c = fscanf(filep, "%lf %lf %lf %lf",
          &objp->shape.sphere.center.x, &objp->shape.sphere.center.y, &objp->shape.sphere.center.z, &objp->shape.sphere.radius);
        return (read_c == 4); }
        else {
        return y;  }
}


int loadShapes(shape_t shapes[]) {
    char file_n[70];
    printf("Enter the file name to read: \n");
    scanf("%s", file_n);

    FILE *filep = fopen(file_n, "r");
    if (filep == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    printf("Opening %s\n", file_n);

 int shapesay;
    shapesay= 0;
    
  for (; !feof(filep) && shapesay < MAX_SHAPES; shapesay++) {
    if (scanShape(filep, &shapes[shapesay])) {
  
    }
}

    printf("Loading complete\n");
    fclose(filep);
    printf("Closing %s\n", file_n);

    return shapesay;
}

void printShape(const shape_t *objp) {
    
 switch (objp->type) {
        case CUBE:
         //   printf("aaa");
            printf("Cube: <%.2lf %.2lf %.2lf> <%.2lf>\n",
                   objp->shape.cube.center.x,
                   objp->shape.cube.center.y,
                   objp->shape.cube.center.z,
                   objp->shape.cube.side);
            break;
        case SQUARE_PRISM:
    //    printf("bbb");
            printf("Square_prism: <%.2lf %.2lf %.2lf> <%.2lf %.2lf>\n",
                   objp->shape.square_prism.center.x,
                   objp->shape.square_prism.center.y,
                   objp->shape.square_prism.center.z,
                   objp->shape.square_prism.base_side,
                   objp->shape.square_prism.height);
            break;
        case SPHERE:
      //  printf("ccc");
            printf("Sphere: <%.2lf %.2lf %.2lf> <%.2lf>\n",
                   objp->shape.sphere.center.x,
                   objp->shape.sphere.center.y,
                   objp->shape.sphere.center.z,
                   objp->shape.sphere.radius);
            break;
    }

}

int main() {
    shape_t shapes[MAX_SHAPES];
    int numOfShapes = loadShapes(shapes);

    printf("\nShapes: 3D\n");
    for (int i = 0; i < numOfShapes; i++)
        printShape(&shapes[i]);

    return 0;
}