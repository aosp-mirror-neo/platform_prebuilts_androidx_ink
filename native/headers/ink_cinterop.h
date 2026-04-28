// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_AFFINE_TRANSFORM_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_AFFINE_TRANSFORM_NATIVE_H_

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  float x;
  float y;
} AffineTransformNative_Vec;

typedef struct {
  AffineTransformNative_Vec center;
  float width;
  float height;
  float rotation_degrees;
  float skew;
} AffineTransformNative_Parallelogram;

AffineTransformNative_Parallelogram AffineTransformNative_apply(
    float a, float b, float c, float d, float e, float f, float quad_center_x,
    float quad_center_y, float quad_width, float quad_height,
    float quad_rotation_degrees, float quad_shear_factor);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_AFFINE_TRANSFORM_NATIVE_H_
// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_ANGLE_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_ANGLE_NATIVE_H_

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

float AngleNative_normalizedRadians(float radians);

float AngleNative_normalizedAboutZeroRadians(float radians);

float AngleNative_normalizedDegrees(float degrees);

float AngleNative_normalizedAboutZeroDegrees(float degrees);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_ANGLE_NATIVE_H_
// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_BOX_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_BOX_NATIVE_H_

#include <stdbool.h>

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  float x;
  float y;
} BoxNative_Vec;

BoxNative_Vec BoxNative_createCenter(float rect_x_min, float rect_y_min,
                                     float rect_x_max, float rect_y_max);

bool BoxNative_containsPoint(float rect_x_min, float rect_y_min,
                             float rect_x_max, float rect_y_max, float point_x,
                             float point_y);

bool BoxNative_containsBox(float rect_x_min, float rect_y_min, float rect_x_max,
                           float rect_y_max, float other_x_min,
                           float other_y_min, float other_x_max,
                           float other_y_max);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_BOX_NATIVE_H_
// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_INTERSECTION_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_INTERSECTION_NATIVE_H_

#include <stdbool.h>
#include <stdint.h>

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

bool IntersectionNative_vecSegmentIntersects(float vec_x, float vec_y,
                                             float segment_start_x,
                                             float segment_start_y,
                                             float segment_end_x,
                                             float segment_end_y);

bool IntersectionNative_vecTriangleIntersects(
    float vec_x, float vec_y, float triangle_p0_x, float triangle_p0_y,
    float triangle_p1_x, float triangle_p1_y, float triangle_p2_x,
    float triangle_p2_y);

bool IntersectionNative_vecBoxIntersects(float vec_x, float vec_y,
                                         float box_x_min, float box_y_min,
                                         float box_x_max, float box_y_max);

bool IntersectionNative_vecParallelogramIntersects(
    float vec_x, float vec_y, float parallelogram_center_x,
    float parallelogram_center_y, float parallelogram_width,
    float parallelogram_height, float parallelogram_angle_radian,
    float parallelogram_shear_factor);

bool IntersectionNative_segmentSegmentIntersects(
    float segment_1_start_x, float segment_1_start_y, float segment_1_end_x,
    float segment_1_end_y, float segment_2_start_x, float segment_2_start_y,
    float segment_2_end_x, float segment_2_end_y);

bool IntersectionNative_segmentTriangleIntersects(
    float segment_start_x, float segment_start_y, float segment_end_x,
    float segment_end_y, float triangle_p0_x, float triangle_p0_y,
    float triangle_p1_x, float triangle_p1_y, float triangle_p2_x,
    float triangle_p2_y);

bool IntersectionNative_segmentBoxIntersects(float segment_start_x,
                                             float segment_start_y,
                                             float segment_end_x,
                                             float segment_end_y,
                                             float box_x_min, float box_y_min,
                                             float box_x_max, float box_y_max);

bool IntersectionNative_segmentParallelogramIntersects(
    float segment_start_x, float segment_start_y, float segment_end_x,
    float segment_end_y, float parallelogram_center_x,
    float parallelogram_center_y, float parallelogram_width,
    float parallelogram_height, float parallelogram_angle_radian,
    float parallelogram_shear_factor);

bool IntersectionNative_triangleTriangleIntersects(
    float triangle_1_p0_x, float triangle_1_p0_y, float triangle_1_p1_x,
    float triangle_1_p1_y, float triangle_1_p2_x, float triangle_1_p2_y,
    float triangle_2_p0_x, float triangle_2_p0_y, float triangle_2_p1_x,
    float triangle_2_p1_y, float triangle_2_p2_x, float triangle_2_p2_y);

bool IntersectionNative_triangleBoxIntersects(
    float triangle_p0_x, float triangle_p0_y, float triangle_p1_x,
    float triangle_p1_y, float triangle_p2_x, float triangle_p2_y,
    float box_x_min, float box_y_min, float box_x_max, float box_y_max);

bool IntersectionNative_triangleParallelogramIntersects(
    float triangle_p0_x, float triangle_p0_y, float triangle_p1_x,
    float triangle_p1_y, float triangle_p2_x, float triangle_p2_y,
    float parallelogram_center_x, float parallelogram_center_y,
    float parallelogram_width, float parallelogram_height,
    float parallelogram_angle_radian, float parallelogram_shear_factor);

bool IntersectionNative_boxBoxIntersects(float box_1_x_min, float box_1_y_min,
                                         float box_1_x_max, float box_1_y_max,
                                         float box_2_x_min, float box_2_y_min,
                                         float box_2_x_max, float box_2_y_max);

bool IntersectionNative_boxParallelogramIntersects(
    float box_x_min, float box_y_min, float box_x_max, float box_y_max,
    float parallelogram_center_x, float parallelogram_center_y,
    float parallelogram_width, float parallelogram_height,
    float parallelogram_angle_radian, float parallelogram_shear_factor);

bool IntersectionNative_parallelogramParallelogramIntersects(
    float parallelogram_1_center_x, float parallelogram_1_center_y,
    float parallelogram_1_width, float parallelogram_1_height,
    float parallelogram_1_angle_in_radian, float parallelogram_1_shear_factor,
    float parallelogram_2_center_x, float parallelogram_2_center_y,
    float parallelogram_2_width, float parallelogram_2_height,
    float parallelogram_2_angle_in_radian, float parallelogram_2_shear_factor);

bool IntersectionNative_partitionedMeshVecIntersects(
    int64_t partitioned_mesh_ptr, float vec_x, float vec_y, float a, float b,
    float c, float d, float e, float f);

bool IntersectionNative_partitionedMeshSegmentIntersects(
    int64_t partitioned_mesh_ptr, float segment_start_x, float segment_start_y,
    float segment_end_x, float segment_end_y, float a, float b, float c,
    float d, float e, float f);

bool IntersectionNative_partitionedMeshTriangleIntersects(
    int64_t partitioned_mesh_ptr, float triangle_p0_x, float triangle_p0_y,
    float triangle_p1_x, float triangle_p1_y, float triangle_p2_x,
    float triangle_p2_y, float a, float b, float c, float d, float e, float f);

bool IntersectionNative_partitionedMeshBoxIntersects(
    int64_t partitioned_mesh_ptr, float box_x_min, float box_y_min,
    float box_x_max, float box_y_max, float a, float b, float c, float d,
    float e, float f);

bool IntersectionNative_partitionedMeshParallelogramIntersects(
    int64_t partitioned_mesh_ptr, float parallelogram_center_x,
    float parallelogram_center_y, float parallelogram_width,
    float parallelogram_height, float parallelogram_angle_radian,
    float parallelogram_shear_factor, float a, float b, float c, float d,
    float e, float f);

bool IntersectionNative_partitionedMeshPartitionedMeshIntersects(
    int64_t this_partitioned_mesh_ptr, int64_t other_partitioned_mesh_ptr,
    float this_a, float this_b, float this_c, float this_d, float this_e,
    float this_f, float other_a, float other_b, float other_c, float other_d,
    float other_e, float other_f);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_INTERSECTION_NATIVE_H_
// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_MESH_FORMAT_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_MESH_FORMAT_NATIVE_H_

#include <stdbool.h>
#include <stdint.h>

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

// The native_ptr parameter of these methods contains the raw pointer to a
// C++ MeshFormat object stored in Kotlin on MeshFormat.nativePointer.

// Returns whether this mesh format has the same packed representation and same
// packing scheme as another MeshFormat, such that they can be passed to the
// same shader that accepts packed attribute values. other_native_ptr is the raw
// pointer to a different MeshFormat object.
bool MeshFormatNative_isPackedEquivalent(int64_t native_ptr,
                                         int64_t other_native_ptr);

// Returns whether this mesh formats has the same unpacked representation as
// another MeshFormat. other_native_ptr is the raw pointer to a different
// MeshFormat object.
bool MeshFormatNative_isUnpackedEquivalent(int64_t native_ptr,
                                           int64_t other_native_ptr);

int MeshFormatNative_attributeCount(int64_t native_ptr);

// Frees a Kotlin MeshFormat.nativePointer.
void MeshFormatNative_free(int64_t native_ptr);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_MESH_FORMAT_NATIVE_H_
// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_MESH_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_MESH_NATIVE_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  float x_min;
  float y_min;
  float x_max;
  float y_max;
} MeshNative_Box;

typedef struct {
  float x;
  float y;
} MeshNative_Vec;

// The native_ptr parameter of these methods contains the raw pointer to a
// C++ Mesh object stored in Kotlin on Mesh.nativePointer.

// Frees a Kotlin Mesh.nativePointer.
void MeshNative_free(int64_t native_ptr);

// Creates a new heap-allocated empty `Mesh` and returns a pointer to it as
// int64_t, suitable for wrapping in a Kotlin Mesh.
int64_t MeshNative_createEmpty();

// Takes a raw pointer to another `Mesh` as int64_t, creates a new
// heap-allocated copy of that, and returns a pointer to it as int64_t, suitable
// fors wrapping in a Kotlin Mesh.
int64_t MeshNative_newCopy(int64_t other_native_ptr);

int MeshNative_getVertexCount(int64_t native_ptr);

int MeshNative_getVertexStride(int64_t native_ptr);

int MeshNative_getTriangleCount(int64_t native_ptr);

int MeshNative_getAttributeCount(int64_t native_ptr);

bool MeshNative_isEmpty(int64_t native_ptr);

// Can only be called if MeshNative_isEmpty returns false.
MeshNative_Box MeshNative_getBounds(int64_t native_ptr);

int MeshNative_fillAttributeUnpackingParams(int64_t native_ptr,
                                            int attribute_index, float* offsets,
                                            float* scales);

int64_t MeshNative_newCopyOfFormat(int64_t native_ptr);

MeshNative_Vec MeshNative_getVertexPosition(int64_t native_ptr,
                                            int vertex_index);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_MESH_NATIVE_H_
// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_PARALLELOGRAM_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_PARALLELOGRAM_NATIVE_H_

#include <stdbool.h>

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  float x;
  float y;
} ParallelogramNative_Vec;

typedef struct {
  ParallelogramNative_Vec first;
  ParallelogramNative_Vec second;
} ParallelogramNative_SemiAxes;

typedef struct {
  float xmin;
  float ymin;
  float xmax;
  float ymax;
} ParallelogramNative_Box;

typedef struct {
  ParallelogramNative_Vec corner1;
  ParallelogramNative_Vec corner2;
  ParallelogramNative_Vec corner3;
  ParallelogramNative_Vec corner4;
} ParallelogramNative_Corners;

ParallelogramNative_Box ParallelogramNative_computeBoundingBox(
    float center_x, float center_y, float width, float height,
    float rotation_degrees, float skew);

ParallelogramNative_SemiAxes ParallelogramNative_computeSemiAxes(
    float center_x, float center_y, float width, float height,
    float rotation_degrees, float skew);

ParallelogramNative_Corners ParallelogramNative_computeCorners(
    float center_x, float center_y, float width, float height,
    float rotation_degrees, float skew);

bool ParallelogramNative_contains(float center_x, float center_y, float width,
                                  float height, float rotation_degrees,
                                  float skew, float point_x, float point_y);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_PARALLELOGRAM_NATIVE_H_
// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_PARTITIONED_MESH_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_PARTITIONED_MESH_NATIVE_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  float x;
  float y;
} PartitionedMeshNative_Vec;

typedef struct {
  float x_min;
  float y_min;
  float x_max;
  float y_max;
} PartitionedMeshNative_Box;

// The native_ptr parameter of these methods contains the raw pointer to a
// C++ PartitionedMesh object stored in Kotlin on PartitionedMesh.nativePointer.

// Frees a Kotlin PartitionedMesh.nativePointer.
void PartitionedMeshNative_free(int64_t native_ptr);

// Creates a new heap-allocated empty `PartitionedMesh` and returns a pointer
// to it as int64_t, suitable for wrapping in a Kotlin PartitionedMesh.
int64_t PartitionedMeshNative_createEmptyForTesting();

// Creates a new heap-allocated `PartitionedMesh` from a triangle and returns a
// pointer to it as int64_t, suitable for wrapping in a Kotlin PartitionedMesh.
int64_t PartitionedMeshNative_createFromTriangleForTesting(
    float triangle_p0_x, float triangle_p0_y, float triangle_p1_x,
    float triangle_p1_y, float triangle_p2_x, float triangle_p2_y);

void PartitionedMeshNative_fillRenderGroupMeshPointers(int64_t native_ptr,
                                                       int group_index,
                                                       int64_t* out_pointers);

int PartitionedMeshNative_getRenderGroupCount(int64_t native_ptr);

// Returns a raw pointer to a new heap-allocated 'MeshFormat' suitable for
// wrapping in a Kotlin MeshFormat.
int64_t PartitionedMeshNative_newCopyOfRenderGroupFormat(int64_t native_ptr,
                                                         int group_index);

int PartitionedMeshNative_getOutlineCount(int64_t native_ptr, int group_index);

int PartitionedMeshNative_getOutlineVertexCount(int64_t native_ptr,
                                                int group_index,
                                                int outline_index);

PartitionedMeshNative_Vec PartitionedMeshNative_getOutlineVertexPosition(
    int64_t native_ptr, int group_index, int outline_index,
    int outline_vertex_index);

bool PartitionedMeshNative_isEmpty(int64_t native_ptr);

// Can only be called if PartitionedMeshNative_isEmpty returns false.
PartitionedMeshNative_Box PartitionedMeshNative_getBounds(int64_t native_ptr);

float PartitionedMeshNative_triangleCoverage(
    int64_t native_ptr, float triangle_p0_x, float triangle_p0_y,
    float triangle_p1_x, float triangle_p1_y, float triangle_p2_x,
    float triangle_p2_y, float a, float b, float c, float d, float e, float f);

float PartitionedMeshNative_boxCoverage(int64_t native_ptr, float x_min,
                                        float y_min, float x_max, float y_max,
                                        float a, float b, float c, float d,
                                        float e, float f);

float PartitionedMeshNative_parallelogramCoverage(
    int64_t native_ptr, float center_x, float center_y, float width,
    float height, float angle_radian, float shear_factor, float a, float b,
    float c, float d, float e, float f);

// other_ptr contains the pointer address of another PartitionedMesh.
float PartitionedMeshNative_partitionedMeshCoverage(int64_t native_ptr,
                                                    int64_t other_ptr, float a,
                                                    float b, float c, float d,
                                                    float e, float f);

bool PartitionedMeshNative_triangleCoverageIsGreaterThan(
    int64_t native_ptr, float triangle_p0_x, float triangle_p0_y,
    float triangle_p1_x, float triangle_p1_y, float triangle_p2_x,
    float triangle_p2_y, float threshold, float a, float b, float c, float d,
    float e, float f);

bool PartitionedMeshNative_boxCoverageIsGreaterThan(
    int64_t native_ptr, float x_min, float y_min, float x_max, float y_max,
    float threshold, float a, float b, float c, float d, float e, float f);

bool PartitionedMeshNative_parallelogramCoverageIsGreaterThan(
    int64_t native_ptr, float center_x, float center_y, float width,
    float height, float angle_radian, float shear_factor, float threshold,
    float a, float b, float c, float d, float e, float f);

bool PartitionedMeshNative_partitionedMeshCoverageIsGreaterThan(
    int64_t native_ptr, int64_t other_ptr, float threshold, float a, float b,
    float c, float d, float e, float f);

void PartitionedMeshNative_initializeSpatialIndex(int64_t native_ptr);

bool PartitionedMeshNative_isSpatialIndexInitialized(int64_t native_ptr);

int PartitionedMeshNative_getRenderGroupMeshCount(int64_t native_ptr,
                                                  int group_index);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_PARTITIONED_MESH_NATIVE_H_
// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_TRIANGLE_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_TRIANGLE_NATIVE_H_

#include <stdbool.h>

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

bool TriangleNative_contains(float triangle_p0_x, float triangle_p0_y,
                             float triangle_p1_x, float triangle_p1_y,
                             float triangle_p2_x, float triangle_p2_y,
                             float point_x, float point_y);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_TRIANGLE_NATIVE_H_
// Copyright 2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_VEC_NATIVE_H_
#define THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_VEC_NATIVE_H_

// C-compatible library header for Kotlin-native bindings.

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  float x;
  float y;
} VecNative_Vec;

VecNative_Vec VecNative_unitVec(float x, float y);

float VecNative_absoluteAngleBetweenInDegrees(float first_vec_x,
                                              float first_vec_y,
                                              float second_vec_x,
                                              float second_vec_y);

float VecNative_signedAngleBetweenInDegrees(float first_vec_x,
                                            float first_vec_y,
                                            float second_vec_x,
                                            float second_vec_y);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_GEOMETRY_INTERNAL_JNI_VEC_NATIVE_H_
