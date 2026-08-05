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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_BEHAVIOR_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_BEHAVIOR_NATIVE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t BrushBehaviorNative_createFromOrderedNodes(
    void* jni_env_pass_through, const int64_t* node_native_pointers,
    int num_nodes, const char* developer_comment,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void BrushBehaviorNative_free(int64_t native_ptr);

int BrushBehaviorNative_getNodeCount(int64_t native_ptr);

int BrushBehaviorNative_getNodeTypeInt(int64_t native_ptr, int index);

const char* BrushBehaviorNative_getDeveloperComment(int64_t native_ptr);

int64_t BrushBehaviorNative_newCopyOfNode(int64_t native_ptr, int index);

int BrushBehaviorNative_calculateMinimumRequiredVersion(int64_t native_ptr);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_BEHAVIOR_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_BEHAVIOR_NODE_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_BEHAVIOR_NODE_NATIVE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// The native_ptr parameter of these methods contains the raw pointer to a
// C++ BrushBehavior::Node object stored in Kotlin.

// If validation fails for any create function, it calls
// throw_from_status_callback with the value passed as jni_env_pass_through,
// the error status code as an int, and the error status message.
int64_t SourceNodeNative_create(
    void* jni_env_pass_through, int source, float source_value_start,
    float source_value_end, int source_out_of_range_behavior,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t ConstantNodeNative_create(
    void* jni_env_pass_through, float value,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t NoiseNodeNative_create(void* jni_env_pass_through, int seed,
                               int vary_over, float base_period,
                               void (*throw_from_status_callback)(void*, int,
                                                                  const char*));

int64_t ToolTypeFilterNodeNative_create(
    void* jni_env_pass_through, bool mouse_enabled, bool touch_enabled,
    bool stylus_enabled, bool unknown_enabled,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t DampingNodeNative_create(
    void* jni_env_pass_through, int damping_source, float damping_gap,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t ResponseNodeNative_create(
    void* jni_env_pass_through, int64_t easing_function_native_pointer,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t IntegralNodeNative_create(
    void* jni_env_pass_through, int integrate_over, float integral_value_start,
    float integral_value_end, int integral_out_of_range_behavior,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t BinaryOpNodeNative_create(
    void* jni_env_pass_through, int operation,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t InterpolationNodeNative_create(
    void* jni_env_pass_through, int interpolation,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t TargetNodeNative_create(
    void* jni_env_pass_through, int target, float target_modifier_start,
    float target_modifier_end,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t PolarTargetNodeNative_create(
    void* jni_env_pass_through, int polar_target, float angle_range_start,
    float angle_range_end, float magnitude_range_start,
    float magnitude_range_end,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void NodeNative_free(int64_t native_ptr);

// SourceNode accessors:
int SourceNodeNative_getSourceInt(int64_t native_ptr);
float SourceNodeNative_getValueRangeStart(int64_t native_ptr);
float SourceNodeNative_getValueRangeEnd(int64_t native_ptr);
int SourceNodeNative_getOutOfRangeBehaviorInt(int64_t native_ptr);

// ConstantNode accessors:
float ConstantNodeNative_getValue(int64_t native_ptr);

// NoiseNode accessors:
int NoiseNodeNative_getSeed(int64_t native_ptr);
int NoiseNodeNative_getVaryOverInt(int64_t native_ptr);
float NoiseNodeNative_getBasePeriod(int64_t native_ptr);

// ToolTypeFilterNode accessors:
bool ToolTypeFilterNodeNative_getMouseEnabled(int64_t native_ptr);
bool ToolTypeFilterNodeNative_getTouchEnabled(int64_t native_ptr);
bool ToolTypeFilterNodeNative_getStylusEnabled(int64_t native_ptr);
bool ToolTypeFilterNodeNative_getUnknownEnabled(int64_t native_ptr);

// DampingNode accessors:
int DampingNodeNative_getDampingSourceInt(int64_t native_ptr);
float DampingNodeNative_getDampingGap(int64_t native_ptr);

// ResponseNode accessors:
int64_t ResponseNodeNative_getResponseCurvePointer(int64_t native_ptr);

// IntegralNode accessors:
int IntegralNodeNative_getIntegrateOverInt(int64_t native_ptr);
float IntegralNodeNative_getValueRangeStart(int64_t native_ptr);
float IntegralNodeNative_getValueRangeEnd(int64_t native_ptr);
int IntegralNodeNative_getOutOfRangeBehaviorInt(int64_t native_ptr);

// BinaryOpNode accessors:
int BinaryOpNodeNative_getOperationInt(int64_t native_ptr);

// InterpolationNode accessors:
int InterpolationNodeNative_getInterpolationInt(int64_t native_ptr);

// TargetNode accessors:
int TargetNodeNative_getTargetInt(int64_t native_ptr);
float TargetNodeNative_getModifierRangeStart(int64_t native_ptr);
float TargetNodeNative_getModifierRangeEnd(int64_t native_ptr);

// PolarTargetNode accessors:
int PolarTargetNodeNative_getTargetInt(int64_t native_ptr);
float PolarTargetNodeNative_getAngleRangeStart(int64_t native_ptr);
float PolarTargetNodeNative_getAngleRangeEnd(int64_t native_ptr);
float PolarTargetNodeNative_getMagnitudeRangeStart(int64_t native_ptr);
float PolarTargetNodeNative_getMagnitudeRangeEnd(int64_t native_ptr);

// Calculate minimum required version:
int NodeNative_calculateMinimumRequiredVersion(int64_t native_ptr);
int SourceNodeNative_getSourceMinimumRequiredVersion(int source_int);
int TargetNodeNative_getTargetMinimumRequiredVersion(int target_int);
int PolarTargetNodeNative_getPolarTargetMinimumRequiredVersion(int target_int);
int BinaryOpNodeNative_getOperationMinimumRequiredVersion(int operation_int);
int OutOfRangeNative_calculateMinimumRequiredVersion(int out_of_range_int);
int ProgressDomainNative_calculateMinimumRequiredVersion(int domain_int);
int InterpolationNodeNative_getInterpolationMinimumRequiredVersion(
    int interpolation_int);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_BEHAVIOR_NODE_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_COAT_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_COAT_NATIVE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t BrushCoatNative_create(int64_t tip_native_pointer,
                               const int64_t* paint_preferences_native_pointers,
                               int num_paint_preferences);

void BrushCoatNative_free(int64_t native_pointer);

bool BrushCoatNative_isCompatibleWithMeshFormat(
    int64_t native_pointer, int64_t mesh_format_native_pointer);

int64_t BrushCoatNative_newCopyOfBrushTip(int64_t native_pointer);

int BrushCoatNative_getBrushPaintPreferencesCount(int64_t native_pointer);

int64_t BrushCoatNative_newCopyOfBrushPaintPreference(int64_t native_pointer,
                                                      int index);

int BrushCoatNative_calculateMinimumRequiredVersion(int64_t native_pointer);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_COAT_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_FAMILY_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_FAMILY_NATIVE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t BrushFamilyNative_create(
    void* jni_env_pass_through, const int64_t* coat_native_pointers,
    int num_coats, int64_t input_model_pointer,
    const char* client_brush_family_id, const char* developer_comment,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void BrushFamilyNative_free(int64_t native_pointer);

// The caller must free the returned string.
const char* BrushFamilyNative_getClientBrushFamilyId(int64_t native_pointer);

// The caller must free the returned string.
const char* BrushFamilyNative_getDeveloperComment(int64_t native_pointer);

int64_t BrushFamilyNative_getTextureAnimationLoopDurationMillis(
    int64_t native_pointer);

int64_t BrushFamilyNative_getBrushCoatCount(int64_t native_pointer);

int64_t BrushFamilyNative_newCopyOfBrushCoat(int64_t native_pointer, int index);

int BrushFamilyNative_getInputModelType(int64_t native_pointer);

int64_t BrushFamilyNative_newCopyOfInputModel(int64_t native_pointer);

int BrushFamilyNative_calculateMinimumRequiredVersion(int64_t native_pointer);

bool BrushFamilyNative_hasFallbacks(int64_t native_pointer);

int64_t InputModelNative_createNoParametersModel(int type);

int64_t InputModelNative_createSlidingWindowModel(int64_t window_size_millis,
                                                  int upsampling_frequency_hz);

int64_t InputModelNative_createSlidingWindowModelWithDefaultParameters();

void InputModelNative_free(int64_t native_pointer);

int64_t InputModelNative_getSlidingWindowDurationMillis(int64_t native_pointer);

int InputModelNative_getSlidingUpsamplingFrequencyHz(int64_t native_pointer);
int InputModelNative_calculateMinimumRequiredVersion(int64_t native_pointer);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_FAMILY_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_NATIVE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t BrushNative_create(
    void* jni_env_pass_through, int64_t family_native_pointer, float color_red,
    float color_green, float color_blue, float color_alpha, int color_space_id,
    float size, float epsilon,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void BrushNative_free(int64_t native_pointer);

int64_t BrushNative_computeComposeColorLong(
    void* jni_env_pass_through, int64_t native_pointer,
    int64_t (*compute_compose_color_long_from_components_callback)(
        void*, int, float, float, float, float));

float BrushNative_getSize(int64_t native_pointer);

float BrushNative_getEpsilon(int64_t native_pointer);

int64_t BrushNative_newCopyOfBrushFamily(int64_t native_pointer);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_PAINT_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_PAINT_NATIVE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t BrushPaintNative_create(
    void* jni_env_pass_through, const int64_t* texture_layer_native_pointers,
    int num_texture_layers, const int64_t* color_function_native_pointers,
    int num_color_functions, int self_overlap_int,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void BrushPaintNative_free(int64_t native_ptr);

int BrushPaintNative_getTextureLayerCount(int64_t native_ptr);

int BrushPaintNative_getTextureLayerMappingInt(int64_t native_ptr, int index);

int64_t BrushPaintNative_newCopyOfTextureLayer(int64_t native_ptr, int index);

int BrushPaintNative_getColorFunctionCount(int64_t native_ptr);

int BrushPaintNative_getColorFunctionParametersTypeInt(int64_t native_ptr,
                                                       int index);

int64_t BrushPaintNative_newCopyOfColorFunction(int64_t native_ptr, int index);

int BrushPaintNative_getSelfOverlapInt(int64_t native_ptr);

bool BrushPaintNative_isCompatibleWithMeshFormat(
    int64_t native_ptr, int64_t mesh_format_native_ptr);

// Native interface for BrushPaint.TextureLayer:

int64_t TilingTextureNative_create(
    void* jni_env_pass_through, const char* client_texture_id, float size_x,
    float size_y, float offset_x, float offset_y, float rotation_degrees,
    int size_unit, int origin, int wrap_x, int wrap_y, int blend_mode,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t StampingTextureNative_create(
    void* jni_env_pass_through, const char* client_texture_id,
    int animation_frames, int animation_rows, int animation_columns,
    int64_t animation_duration_millis, int animation_repeat_mode,
    int blend_mode,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void TextureLayerNative_free(int64_t native_ptr);

const char* TilingTextureNative_getClientTextureId(int64_t native_ptr);

float TilingTextureNative_getSizeX(int64_t native_ptr);

float TilingTextureNative_getSizeY(int64_t native_ptr);

float TilingTextureNative_getOffsetX(int64_t native_ptr);

float TilingTextureNative_getOffsetY(int64_t native_ptr);

float TilingTextureNative_getRotationDegrees(int64_t native_ptr);

const char* StampingTextureNative_getClientTextureId(int64_t native_ptr);

int StampingTextureNative_getAnimationFrames(int64_t native_ptr);

int StampingTextureNative_getAnimationRows(int64_t native_ptr);

int StampingTextureNative_getAnimationColumns(int64_t native_ptr);

int64_t StampingTextureNative_getAnimationDurationMillis(int64_t native_ptr);

int StampingTextureNative_getAnimationRepeatModeInt(int64_t native_ptr);

int TilingTextureNative_getSizeUnitInt(int64_t native_ptr);

int TilingTextureNative_getOriginInt(int64_t native_ptr);

int TextureLayerNative_getMappingInt(int64_t native_ptr);

int TilingTextureNative_getWrapXInt(int64_t native_ptr);

int TilingTextureNative_getWrapYInt(int64_t native_ptr);

int TextureLayerNative_getBlendModeInt(int64_t native_ptr);

// Native interface for BrushPaint.ColorFunction:

int64_t ColorFunctionNative_createOpacityMultiplier(
    void* jni_env_pass_through, float multiplier,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t ColorFunctionNative_createHueOffset(
    void* jni_env_pass_through, float offsetDegrees,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t ColorFunctionNative_createSaturationMultiplier(
    void* jni_env_pass_through, float multiplier,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t ColorFunctionNative_createLuminosityOffset(
    void* jni_env_pass_through, float offset,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t ColorFunctionNative_createReplaceColor(
    void* jni_env_pass_through, float color_red, float color_green,
    float color_blue, float color_alpha, int color_space_id,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void ColorFunctionNative_free(int64_t native_ptr);

float ColorFunctionNative_getOpacityMultiplier(int64_t native_ptr);

float ColorFunctionNative_getHueOffsetDegrees(int64_t native_ptr);

float ColorFunctionNative_getSaturationMultiplier(int64_t native_ptr);

float ColorFunctionNative_getLuminosityOffset(int64_t native_ptr);

int64_t ColorFunctionNative_computeReplaceColorLong(
    void* jni_env_pass_through, int64_t native_ptr,
    int64_t (*compose_color_long_from_components_callback)(void*, int, float,
                                                           float, float,
                                                           float));

int64_t ColorFunctionNative_computeTransformedColorLong(
    void* jni_env_pass_through, int64_t native_ptr, float color_red,
    float color_green, float color_blue, float color_alpha, int color_space_id,
    int64_t (*compose_color_long_from_components_callback)(void*, int, float,
                                                           float, float,
                                                           float));

int BrushPaintNative_calculateMinimumRequiredVersion(int64_t native_ptr);
int BrushPaintNative_getBlendModeMinimumRequiredVersion(int blend_mode_int);
int BrushPaintNative_getTextureWrapMinimumRequiredVersion(int wrap_int);
int BrushPaintNative_getTextureOriginMinimumRequiredVersion(int origin_int);
int BrushPaintNative_getTextureSizeUnitMinimumRequiredVersion(
    int size_unit_int);
int BrushPaintNative_getAnimationRepeatModeMinimumRequiredVersion(
    int animation_repeat_mode_int);
int TextureLayerNative_calculateMinimumRequiredVersion(int64_t native_ptr);
int ColorFunctionNative_calculateMinimumRequiredVersion(int64_t native_ptr);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_PAINT_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_TIP_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_TIP_NATIVE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t BrushTipNative_create(
    void* jni_env_pass_through, float scale_x, float scale_y,
    float corner_rounding, float slant_degrees, float pinch,
    float rotation_degrees, float particle_gap_distance_scale,
    int64_t particle_gap_duration_millis,
    const int64_t* behavior_native_pointers, int num_behaviors,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void BrushTipNative_free(int64_t native_ptr);

float BrushTipNative_getScaleX(int64_t native_ptr);

float BrushTipNative_getScaleY(int64_t native_ptr);

float BrushTipNative_getCornerRounding(int64_t native_ptr);

float BrushTipNative_getSlantDegrees(int64_t native_ptr);

float BrushTipNative_getPinch(int64_t native_ptr);

float BrushTipNative_getRotationDegrees(int64_t native_ptr);

float BrushTipNative_getParticleGapDistanceScale(int64_t native_ptr);

int64_t BrushTipNative_getParticleGapDurationMillis(int64_t native_ptr);

int BrushTipNative_getBehaviorCount(int64_t native_ptr);

int64_t BrushTipNative_newCopyOfBrushBehavior(int64_t native_ptr, int index);

int BrushTipNative_calculateMinimumRequiredVersion(int64_t native_ptr);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_BRUSH_TIP_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_EASING_FUNCTION_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_EASING_FUNCTION_NATIVE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// The native_ptr parameter of these methods contains the raw pointer to a
// C++ EasingFunction object stored in Kotlin on EasingFunction.nativePointer.

// Creates a new heap-allocated copy of the C++ EasingFunction pointed to by
// other_native_ptr and returns a pointer to it as int64_t, suitable for
// wrapping in a Kotlin EasingFunction.
int64_t EasingFunctionNative_createCopyOf(int64_t other_native_ptr);

// Creates a new heap-allocated C++ EasingFunction with
// EasingFunction::Predefined parameters and returns a pointer to it as
// int64_t, suitable for wrapping in a Kotlin EasingFunction. If validation
// fails, calls throw_from_status_callback with the value passed as
// jni_env_pass_through, the error status code as an int, and the error status
// message.
int64_t EasingFunctionNative_createPredefined(
    void* jni_env_pass_through, int value,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

// Creates a new heap-allocated C++ EasingFunction with
// EasingFunction::CubicBezier parameters and returns a pointer to it as
// int64_t, suitable for wrapping in a Kotlin EasingFunction. If validation
// fails, calls throw_from_status_callback as above.
int64_t EasingFunctionNative_createCubicBezier(
    void* jni_env_pass_through, float x1, float y1, float x2, float y2,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

// Creates a new heap-allocated C++ EasingFunction with
// EasingFunction::Linear parameters and returns a pointer to it as
// int64_t, suitable for wrapping in a Kotlin EasingFunction.
// The points argument is a pointer to an array of floats of size
// num_coords, consisting of interleaved x- and y-coordinates. If validation
// fails, calls throw_from_status_callback as above.
int64_t EasingFunctionNative_createLinear(
    void* jni_env_pass_through, const float* points, int num_coords,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

// Creates a new heap-allocated C++ EasingFunction with
// EasingFunction::Steps parameters and returns a pointer to it as
// int64_t, suitable for wrapping in a Kotlin EasingFunction. If validation
// fails, calls throw_from_status_callback as above.
int64_t EasingFunctionNative_createSteps(
    void* jni_env_pass_through, int step_count, int step_position,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

// Frees a Kotlin EasingFunction.nativePointer.
void EasingFunctionNative_free(int64_t native_ptr);

int EasingFunctionNative_getParametersType(int64_t native_ptr);

int EasingFunctionNative_getPredefinedValueInt(int64_t native_ptr);

float EasingFunctionNative_getCubicBezierX1(int64_t native_ptr);
float EasingFunctionNative_getCubicBezierY1(int64_t native_ptr);
float EasingFunctionNative_getCubicBezierX2(int64_t native_ptr);
float EasingFunctionNative_getCubicBezierY2(int64_t native_ptr);

int EasingFunctionNative_getLinearNumPoints(int64_t native_ptr);
float EasingFunctionNative_getLinearPointX(int64_t native_ptr, int index);
float EasingFunctionNative_getLinearPointY(int64_t native_ptr, int index);

int EasingFunctionNative_getStepsCount(int64_t native_ptr);
int EasingFunctionNative_getStepsPositionInt(int64_t native_ptr);

int EasingFunctionNative_calculateMinimumRequiredVersion(int64_t native_ptr);
int EasingFunctionNative_getStepPositionMinimumRequiredVersion(
    int step_position_int);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_EASING_FUNCTION_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_INPUT_TOOL_TYPE_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_INPUT_TOOL_TYPE_NATIVE_H_

#ifdef __cplusplus
extern "C" {
#endif

int InputToolTypeNative_calculateMinimumRequiredVersion(int tool_type_int);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_INPUT_TOOL_TYPE_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_SELF_OVERLAP_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_SELF_OVERLAP_NATIVE_H_

#ifdef __cplusplus
extern "C" {
#endif

int SelfOverlapNative_calculateMinimumRequiredVersion(int self_overlap_int);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_SELF_OVERLAP_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_STOCK_BRUSHES_NATIVE_H_
#define THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_STOCK_BRUSHES_NATIVE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t StockBrushesNative_createMarker(int version);

int64_t StockBrushesNative_createDashedLine(int version);

int64_t StockBrushesNative_createPressurePen(int version);

int64_t StockBrushesNative_createHighlighter(int self_overlap, int version);

int64_t StockBrushesNative_createEmojiHighlighter(const char* client_texture_id,
                                                  bool show_mini_emoji_trail,
                                                  int self_overlap,
                                                  int version);

int64_t StockBrushesNative_createPredictionFadeOutBehavior();

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_BRUSH_INTERNAL_JNI_STOCK_BRUSHES_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_KMP_STATUS_NATIVE_H_
#define THIRD_PARTY_INK_KMP_STATUS_NATIVE_H_

#ifdef __cplusplus
extern "C" {
#endif

int StatusNative_statusCodeOk();

int StatusNative_statusCodeFailedPrecondition();

int StatusNative_statusCodeInvalidArgument();

int StatusNative_statusCodeNotFound();

int StatusNative_statusCodeOutOfRange();

int StatusNative_statusCodeUnimplemented();

void StatusNative_throwExceptionFromOkStatusForTesting(
    void* jni_env_pass_through,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void StatusNative_throwExceptionFromFailedPreconditionForTesting(
    void* jni_env_pass_through,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str),
    const char* message);

void StatusNative_throwExceptionFromInvalidArgumentForTesting(
    void* jni_env_pass_through,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str),
    const char* message);

void StatusNative_throwExceptionFromNotFoundForTesting(
    void* jni_env_pass_through,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str),
    const char* message);

void StatusNative_throwExceptionFromOutOfRangeForTesting(
    void* jni_env_pass_through,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str),
    const char* message);

void StatusNative_throwExceptionFromUnimplementedForTesting(
    void* jni_env_pass_through,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str),
    const char* message);

void StatusNative_throwExceptionFromUnknownStatusCodeForTesting(
    void* jni_env_pass_through,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str),
    int status_code, const char* message);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_KMP_STATUS_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_STORAGE_INTERNAL_JNI_BRUSH_FAMILY_SERIALIZATION_NATIVE_H_
#define THIRD_PARTY_INK_STORAGE_INTERNAL_JNI_BRUSH_FAMILY_SERIALIZATION_NATIVE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t BrushFamilySerializationNative_createFromProto(
    void* jni_env_pass_through,
    void* on_decode_texture_pass_through, const int8_t* byte_array,
    int size, int max_version,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str),
    const char* (*on_decode_texture_callback)(void* pass_through,
                                              const char* encoded_id,
                                              const int8_t* bitmap,
                                              int bitmap_size));

int8_t* BrushFamilySerializationNative_encode(
    void* alloc_native_array_pass_through, int64_t native_pointer,
    const char** texture_ids, const int8_t** bitmaps, const int* bitmap_lengths,
    int num_textures,
    int8_t* (*alloc_native_array_callback)(void* pass_through, int size));

int8_t* BrushFamilySerializationNative_encodeMultiple(
    void* alloc_native_array_pass_through, int64_t* native_pointers,
    int num_brush_families, const char** texture_ids, const int8_t** bitmaps,
    const int* bitmap_lengths, int num_textures,
    int8_t* (*alloc_native_array_callback)(void* pass_through, int size));

int64_t MultipleBrushFamiliesNative_createFromProto(
    void* jni_env_pass_through,
    void* on_decode_texture_pass_through, const int8_t* byte_array,
    int size, int max_version,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str),
    const char* (*on_decode_texture_callback)(void* pass_through,
                                              const char* encoded_id,
                                              const int8_t* bitmap,
                                              int bitmap_size));

int MultipleBrushFamiliesNative_getBrushFamilyCount(int64_t native_pointer);

int64_t MultipleBrushFamiliesNative_releaseBrushFamily(int64_t native_pointer,
                                                       int index);

void MultipleBrushFamiliesNative_free(int64_t native_pointer);

#ifdef __cplusplus
}
#endif

#endif  // THIRD_PARTY_INK_STORAGE_INTERNAL_JNI_BRUSH_FAMILY_SERIALIZATION_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_STORAGE_INTERNAL_JNI_STROKE_INPUT_BATCH_SERIALIZATION_NATIVE_H_
#define THIRD_PARTY_INK_STORAGE_INTERNAL_JNI_STROKE_INPUT_BATCH_SERIALIZATION_NATIVE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// byte_array contains a serialized ink.proto.CodedStrokeInputBatch. If
// the array is empty, byte_array will be nullptr.
int64_t StrokeInputBatchSerializationNative_createFromProto(
    void* jni_env_pass_through, const int8_t* byte_array, int size,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

// native_ptr is a raw pointer to an ink::StrokeInputBatch.
//
// alloc_native_array_callback is responsible for synchronously allocating an
// array of the size needed to encode the proto and returning a pointer to the
// first element in a context that is later read and cleaned up by the caller.
// alloc_native_array_pass_through is the pass-through parameter for that
// callback (e.g. in Kotlin-Native this will point to
// StableRef<androidx.ink.storage.ByteArrayAlloc>, in JNI it will point
// to ink::jni::JvmByteArrayNativeAlloc).
int8_t* StrokeInputBatchSerializationNative_encode(
    void* alloc_native_array_pass_through, int64_t native_pointer,
    int8_t* (*alloc_native_array_callback)(void* pass_through, int size));

#ifdef __cplusplus
}
#endif

#endif  // THIRD_PARTY_INK_STORAGE_INTERNAL_JNI_STROKE_INPUT_BATCH_SERIALIZATION_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_STROKES_INTERNAL_JNI_IN_PROGRESS_STROKE_NATIVE_H_
#define THIRD_PARTY_INK_STROKES_INTERNAL_JNI_IN_PROGRESS_STROKE_NATIVE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int tool_type_int;
  float x;
  float y;
  int64_t elapsed_time_millis;
  float stroke_unit_length_cm;
  float pressure;
  float tilt_radians;
  float orientation_radians;
} InProgressStrokeNative_Input;

typedef struct {
  float x;
  float y;
} InProgressStrokeNative_Vec;

typedef struct {
  float min_x;
  float min_y;
  float max_x;
  float max_y;
} InProgressStrokeNative_Box;

// Construct a native InProgressStroke and return a pointer to it as a long.
int64_t InProgressStrokeNative_create();

void InProgressStrokeNative_free(int64_t native_pointer);

void InProgressStrokeNative_clear(int64_t native_pointer);

// Starts the stroke with a brush.
void InProgressStrokeNative_start(int64_t native_pointer,
                                  int64_t brush_native_pointer, int noise_seed,
                                  float base_animation_phase);

bool InProgressStrokeNative_enqueueInputs(
    void* jni_env_pass_through, int64_t native_pointer,
    int64_t real_inputs_pointer, int64_t predicted_inputs_pointer,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

bool InProgressStrokeNative_updateShape(
    void* jni_env_pass_through, int64_t native_pointer,
    int64_t j_current_elapsed_time_millis,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

void InProgressStrokeNative_finishInput(int64_t native_pointer);

bool InProgressStrokeNative_isInputFinished(int64_t native_pointer);

bool InProgressStrokeNative_isUpdateNeeded(int64_t native_pointer);

bool InProgressStrokeNative_changesWithTime(int64_t native_pointer);

int64_t InProgressStrokeNative_newStrokeFromCopy(int64_t native_pointer);

int64_t InProgressStrokeNative_newStrokeFromPrunedCopy(int64_t native_pointer);

int InProgressStrokeNative_getInputCount(int64_t native_pointer);

int InProgressStrokeNative_getRealInputCount(int64_t native_pointer);

int InProgressStrokeNative_getPredictedInputCount(int64_t native_pointer);

void InProgressStrokeNative_populateInputs(
    int64_t native_pointer, int64_t mutable_stroke_input_batch_pointer,
    int from, int to);

InProgressStrokeNative_Input InProgressStrokeNative_getInput(
    int64_t native_pointer, int index);

float InProgressStrokeNative_getBaseAnimationPhase(int64_t native_pointer);

int InProgressStrokeNative_getBrushCoatCount(int64_t native_pointer);

bool InProgressStrokeNative_hasMeshBounds(int64_t native_pointer,
                                          int coat_index);

// Cannot be called unless InProgressStrokeNative_hasMeshBounds is true for that
// coat index.
InProgressStrokeNative_Box InProgressStrokeNative_getMeshBounds(
    int64_t native_pointer, int coat_index);

bool InProgressStrokeNative_hasUpdatedRegion(int64_t native_pointer);

// Cannot be called unless hasUpdateRegion is true.
InProgressStrokeNative_Box InProgressStrokeNative_getUpdatedRegion(
    int64_t native_pointer);

void InProgressStrokeNative_resetUpdatedRegion(int64_t native_pointer);

int InProgressStrokeNative_getOutlineCount(int64_t native_pointer,
                                           int coat_index);

int InProgressStrokeNative_getOutlineVertexCount(int64_t native_pointer,
                                                 int coat_index,
                                                 int outline_index);

InProgressStrokeNative_Vec InProgressStrokeNative_getOutlinePosition(
    int64_t native_pointer, int coat_index, int outline_index,
    int outline_vertex_index);

InProgressStrokeNative_Vec InProgressStrokeNative_getPosition(
    int64_t native_pointer, int coat_index, int partition_index,
    int vertex_index);

int InProgressStrokeNative_getMeshPartitionCount(int64_t native_pointer,
                                                 int coat_index);

int InProgressStrokeNative_getVertexCount(int64_t native_pointer,
                                          int coat_index, int mesh_index);

// Return a newly allocated copy of the given `Mesh`'s `MeshFormat`.
int64_t InProgressStrokeNative_newCopyOfMeshFormat(int64_t native_pointer,
                                                   int coat_index);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_STROKES_INTERNAL_JNI_IN_PROGRESS_STROKE_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_STROKES_INTERNAL_JNI_MESH_CREATION_NATIVE_H_
#define THIRD_PARTY_INK_STROKES_INTERNAL_JNI_MESH_CREATION_NATIVE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Creates a closed shape from the given stroke input batch and returns the
// native pointer to the resulting PartitionedMesh.
int64_t MeshCreationNative_createClosedShapeFromStrokeInputBatch(
    void* jni_env_pass_through, int64_t stroke_input_batch_native_pointer,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_STROKES_INTERNAL_JNI_MESH_CREATION_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_STROKES_INTERNAL_JNI_STROKE_INPUT_BATCH_NATIVE_H_
#define THIRD_PARTY_INK_STROKES_INTERNAL_JNI_STROKE_INPUT_BATCH_NATIVE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int tool_type_int;
  float x;
  float y;
  int64_t elapsed_time_millis;
  float stroke_unit_length_cm;
  float pressure;
  float tilt_radians;
  float orientation_radians;
} StrokeInputBatchNative_Input;

int64_t StrokeInputBatchNative_create(void);

void StrokeInputBatchNative_free(int64_t native_pointer);

int StrokeInputBatchNative_getSize(int64_t native_pointer);

StrokeInputBatchNative_Input StrokeInputBatchNative_getStrokeInput(
    int64_t native_pointer, int index);

int64_t StrokeInputBatchNative_getDurationMillis(int64_t native_pointer);

int StrokeInputBatchNative_getToolType(int64_t native_pointer);

float StrokeInputBatchNative_getStrokeUnitLengthCm(int64_t native_pointer);

bool StrokeInputBatchNative_hasStrokeUnitLength(int64_t native_pointer);

bool StrokeInputBatchNative_hasPressure(int64_t native_pointer);

bool StrokeInputBatchNative_hasTilt(int64_t native_pointer);

bool StrokeInputBatchNative_hasOrientation(int64_t native_pointer);

int StrokeInputBatchNative_getNoiseSeed(int64_t native_pointer);

float StrokeInputBatchNative_getBaseAnimationPhase(int64_t native_pointer);

void MutableStrokeInputBatchNative_clear(int64_t native_pointer);

bool MutableStrokeInputBatchNative_appendSingle(
    void* jni_env_pass_through, int64_t native_pointer, int tool_type, float x,
    float y, int64_t elapsed_time_millis, float stroke_unit_length_cm,
    float pressure, float tilt, float orientation,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

bool MutableStrokeInputBatchNative_appendBatch(
    void* jni_env_pass_through, int64_t native_pointer,
    int64_t append_from_native_pointer,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int64_t MutableStrokeInputBatchNative_newCopy(int64_t native_pointer);

void MutableStrokeInputBatchNative_setNoiseSeed(int64_t native_pointer,
                                                int seed);

void MutableStrokeInputBatchNative_setBaseAnimationPhase(int64_t native_pointer,
                                                         float phase);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_STROKES_INTERNAL_JNI_STROKE_INPUT_BATCH_NATIVE_H_
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

#ifndef THIRD_PARTY_INK_STROKES_INTERNAL_JNI_STROKE_NATIVE_H_
#define THIRD_PARTY_INK_STROKES_INTERNAL_JNI_STROKE_NATIVE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t StrokeNative_createWithBrushAndInputs(int64_t brush_native_pointer,
                                              int64_t inputs_native_pointer);

int64_t StrokeNative_createWithBrushInputsAndShape(
    int64_t brush_native_pointer, int64_t inputs_native_pointer,
    int64_t partitioned_mesh_native_pointer);

// Make a heap-allocated shallow (doesn't replicate all the individual input
// points) copy of the `StrokeInputBatch` belonging to this `Stroke`. Return
// the raw pointer to this copy, so that it can be wrapped by a JVM
// `StrokeInputBatch`, which is responsible for freeing the copy when it is
// garbage collected and finalized.
int64_t StrokeNative_newShallowCopyOfInputs(int64_t native_pointer_to_stroke);

// Make a heap-allocated shallow (doesn't replicate all the individual meshes)
// copy of the `PartitionedMesh` belonging to this `Stroke`. Return the raw
// pointer to this copy, so that it can be wrapped by a JVM `PartitionedMesh`,
// which is responsible for freeing the copy when it is garbage collected and
// finalized.
int64_t StrokeNative_newShallowCopyOfShape(int64_t native_pointer_to_stroke);

void StrokeNative_free(int64_t native_pointer_to_stroke);

// Returns a pointer to hold the result of a geometric subtraction.
int64_t StrokeNative_createWithSubtract(
    int64_t target_stroke_ptr, int64_t mask_shape_ptr, float mask_a,
    float mask_b, float mask_c, float mask_d, float mask_e, float mask_f,
    float stroke_a, float stroke_b, float stroke_c, float stroke_d,
    float stroke_e, float stroke_f);

int64_t MultipleStrokesNative_createWithSplit(
    void* jni_env_pass_through, int64_t target_stroke_ptr, float transform_a,
    float transform_b, float transform_c, float transform_d, float transform_e,
    float transform_f, float tolerance,
    void (*throw_from_status_callback)(void* jni_env, int status_code,
                                       const char* status_str));

int32_t MultipleStrokesNative_getStrokeCount(int64_t native_pointer);

// Releases the pointer to i-th stroke in partial erase result, to be wrapped
// in a Kotlin `Stroke`.
int64_t MultipleStrokesNative_releaseStroke(int64_t native_pointer,
                                            int32_t index);

// Frees the remaining result of the partial erase.
void MultipleStrokesNative_free(int64_t native_pointer);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THIRD_PARTY_INK_STROKES_INTERNAL_JNI_STROKE_NATIVE_H_
