#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SHAPES 100

typedef struct {
    double x;
    double y;
    double z;
} point_t;

typedef struct {
    point_t center;
    double side;
} cube_t;

typedef struct {
    point_t center;
    double base_side;
    double height;
} square_prism_t;

typedef struct {
    point_t center;
    double radius;
} sphere_t;

typedef enum {
    CUBE,
    SQUARE_PRISM,
    SPHERE
} shape_type_t;

typedef struct {
    shape_type_t type;
    union {
        cube_t cube;
        square_prism_t square_prism;
        sphere_t sphere;
    } shape;
} shape_t;

int loadShapes(shape_t *shapes, const char *filename) {
    FILE *filep = fopen(filename, "r");
    if (filep == NULL) {
        printf("Failed to open %s\n", filename);
        return 0;
    }

    int shapeCount = 0;
    char shptp[20];

    printf("Opening %s\n", filename);

    while (fscanf(filep, "%s", shptp) == 1) {
        if (strcmp(shptp, "cube") == 0) {
            shapes[shapeCount].type = CUBE;
            fscanf(filep, "%lf %lf %lf %lf",
                   &shapes[shapeCount].shape.cube.center.x,
                   &shapes[shapeCount].shape.cube.center.y,
                   &shapes[shapeCount].shape.cube.center.z,
                   &shapes[shapeCount].shape.cube.side);
            shapeCount++;
        } else if (strcmp(shptp, "square_prism") == 0) {
            shapes[shapeCount].type = SQUARE_PRISM;
            fscanf(filep, "%lf %lf %lf %lf %lf",
                   &shapes[shapeCount].shape.square_prism.center.x,
                   &shapes[shapeCount].shape.square_prism.center.y,
                   &shapes[shapeCount].shape.square_prism.center.z,
                   &shapes[shapeCount].shape.square_prism.base_side,
                   &shapes[shapeCount].shape.square_prism.height);
            shapeCount++;
        } else if (strcmp(shptp, "sphere") == 0) {
            shapes[shapeCount].type = SPHERE;
            fscanf(filep, "%lf %lf %lf %lf",
                   &shapes[shapeCount].shape.sphere.center.x,
                   &shapes[shapeCount].shape.sphere.center.y,
                   &shapes[shapeCount].shape.sphere.center.z,
                   &shapes[shapeCount].shape.sphere.radius);
            shapeCount++;
        }
    }

    printf("Loading complete\n");
    fclose(filep);
    printf("Closing %s\n", filename);

    return shapeCount;
}

void printShapes(const shape_t *shapes, int shapeCount) {
    printf("Shapes 3D:\n");
    int i = 0;
    while (i < shapeCount) {
        if (shapes[i].type == CUBE) {
            printf("Cube: <%.2lf %.2lf %.2lf> <%.2lf>\n",
                   shapes[i].shape.cube.center.x,
                //   printf("%s", shapes[i]);
                   shapes[i].shape.cube.center.y,
                   shapes[i].shape.cube.center.z,
                      //   printf("%s", shapes[i]);
                   shapes[i].shape.cube.side);
        } else if (shapes[i].type == SQUARE_PRISM) {
            printf("Square_prism: <%.2lf %.2lf %.2lf> <%.2lf %.2lf>\n",
                   shapes[i].shape.square_prism.center.x,
                      //   printf("%s", shapes[i]);
                   shapes[i].shape.square_prism.center.y,
                   shapes[i].shape.square_prism.center.z,
                      //   printf("%s", shapes[i]);
                   shapes[i].shape.square_prism.base_side,
                   shapes[i].shape.square_prism.height);
        } else if (shapes[i].type == SPHERE) {
            printf("Sphere: <%.2lf %.2lf %.2lf> <%.2lf>\n",
                   shapes[i].shape.sphere.center.x,
                   
                      //   printf("%s", shapes[i]);
                   shapes[i].shape.sphere.center.y,
                   shapes[i].shape.sphere.center.z,
                   shapes[i].shape.sphere.radius);
                      //   printf("%s", shapes[i]);
        }
        i++;
           //   printf("%s", shapes[i]);
    }
}

int isInside(const point_t *ptp1, const point_t *ptp2, const shape_t *objp) {
    double xx, yy, zz, XX, YY, ZZ;

    if (objp->type == CUBE) {
        xx = objp->shape.cube.center.x - objp->shape.cube.side / 2.0;
           //   printf("%d",min);
        yy = objp->shape.cube.center.y - objp->shape.cube.side / 2.0;
        zz = objp->shape.cube.center.z - objp->shape.cube.side / 2.0;
        XX = objp->shape.cube.center.x + objp->shape.cube.side / 2.0;
        YY = objp->shape.cube.center.y + objp->shape.cube.side / 2.0;
        ZZ = objp->shape.cube.center.z + objp->shape.cube.side / 2.0;
    } else if (objp->type == SQUARE_PRISM) {
        xx = objp->shape.square_prism.center.x - objp->shape.square_prism.base_side / 2.0;
        yy = objp->shape.square_prism.center.y - objp->shape.square_prism.base_side / 2.0;
        zz = objp->shape.square_prism.center.z;
        XX = objp->shape.square_prism.center.x + objp->shape.square_prism.base_side / 2.0;
        YY = objp->shape.square_prism.center.y + objp->shape.square_prism.base_side / 2.0;
        ZZ = objp->shape.square_prism.center.z + objp->shape.square_prism.height;
    } else if (objp->type == SPHERE) {
        xx = objp->shape.sphere.center.x - objp->shape.sphere.radius;
        yy = objp->shape.sphere.center.y - objp->shape.sphere.radius;
        zz = objp->shape.sphere.center.z - objp->shape.sphere.radius;
        XX = objp->shape.sphere.center.x + objp->shape.sphere.radius;
        YY = objp->shape.sphere.center.y + objp->shape.sphere.radius;
        ZZ = objp->shape.sphere.center.z + objp->shape.sphere.radius;
    } else {
        return 0;
    }

    if ((ptp1->x >= xx && ptp1->x <= XX) &&
        (ptp1->y >= yy && ptp1->y <= YY) &&
        (ptp1->z >= zz && ptp1->z <= ZZ) &&
        (ptp2->x >= xx && ptp2->x <= XX) &&
        (ptp2->y >= yy && ptp2->y <= YY) &&
        (ptp2->z >= zz && ptp2->z <= ZZ)) {
        return 1;
    }

    return 0;
}

int main() {
    char filename[100];
    printf("Enter the file name to read: ");
    scanf("%s", filename);

    shape_t shapes[MAX_SHAPES];
    int shapeCount = loadShapes(shapes, filename);

    printShapes(shapes, shapeCount);

    point_t ptp1, ptp2;
    printf("Enter x,y and z coordinate of the start point of line: \n");
    scanf("%lf %lf %lf", &ptp1.x, &ptp1.y, &ptp1.z);
    printf("Enter x,y and z coordinate of the end point of line: \n");
    scanf("%lf %lf %lf", &ptp2.x, &ptp2.y, &ptp2.z);

    int insideCount = 0;
    printf("The Line from <%.2lf %.2lf %.2lf>  to <%.2lf %.2lf %.2lf> is inside the following shapes:\n",
           ptp1.x, ptp1.y, ptp1.z, ptp2.x, ptp2.y, ptp2.z);
    int i = 0;
    while (i < shapeCount) {
        if (isInside(&ptp1, &ptp2, &shapes[i])) {
            insideCount++;
            if (shapes[i].type == CUBE) {
                printf("Cube: <%.2lf %.2lf %.2lf> <%.2lf>\n",
                       shapes[i].shape.cube.center.x,
                       shapes[i].shape.cube.center.y,
                       shapes[i].shape.cube.center.z,
                       shapes[i].shape.cube.side);
            } else if (shapes[i].type == SPHERE) {
                printf("Sphere: <%.2lf %.2lf %.2lf> <%.2lf>\n",
                       shapes[i].shape.sphere.center.x,
                       shapes[i].shape.sphere.center.y,
                       shapes[i].shape.sphere.center.z,
                       shapes[i].shape.sphere.radius);
            }
        }
        i++;
    }

    if (insideCount == 0) {
        printf("None\n");
    }

    return 0;
}