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
