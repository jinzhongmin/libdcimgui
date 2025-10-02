#include "dcimplot.h"
#include "imgui.h"
#include "implot.h"
#include <cstdint>

CIMPLOT_API ImPlotContext *ImPlot_CreateContext() {
  return ImPlot::CreateContext();
}
CIMPLOT_API void ImPlot_DestroyContext(ImPlotContext *ctx) {
  ImPlot::DestroyContext(ctx);
}
CIMPLOT_API ImPlotContext *ImPlot_GetCurrentContext() {
  return ImPlot::GetCurrentContext();
}
CIMPLOT_API void ImPlot_SetCurrentContext(ImPlotContext *ctx) {
  ImPlot::SetCurrentContext(ctx);
}
CIMPLOT_API void ImPlot_SetImGuiContext(ImGuiContext *ctx) {
  ImPlot::SetImGuiContext(ctx);
}
CIMPLOT_API bool ImPlot_BeginPlot(const char *title_id, const ImVec2 size,
                                  ImPlotFlags flags) {
  return ImPlot::BeginPlot(title_id, size, flags);
}
CIMPLOT_API void ImPlot_EndPlot() { ImPlot::EndPlot(); }

CIMPLOT_API bool ImPlot_BeginSubplots(const char *title_id, int rows, int cols,
                                      const ImVec2 size,
                                      ImPlotSubplotFlags flags,
                                      float *row_ratios, float *col_ratios) {
  return ImPlot::BeginSubplots(title_id, rows, cols, size, flags, row_ratios,
                               col_ratios);
}
CIMPLOT_API void ImPlot_EndSubplots() { ImPlot::EndSubplots(); }

CIMPLOT_API void ImPlot_SetupAxis(ImAxis axis, const char *label,
                                  ImPlotAxisFlags flags) {
  ImPlot::SetupAxis(axis, label, flags);
}
CIMPLOT_API void ImPlot_SetupAxisLimits(ImAxis axis, double v_min, double v_max,
                                        ImPlotCond cond) {
  ImPlot::SetupAxisLimits(axis, v_min, v_max, cond);
}
CIMPLOT_API void ImPlot_SetupAxisLinks(ImAxis axis, double *link_min,
                                       double *link_max) {
  ImPlot::SetupAxisLinks(axis, link_min, link_max);
}
CIMPLOT_API void ImPlot_SetupAxisFormat(ImAxis axis, const char *fmt) {
  ImPlot::SetupAxisFormat(axis, fmt);
}
CIMPLOT_API void ImPlot_SetupAxisFormatCallback(ImAxis axis,
                                                ImPlotFormatter formatter,
                                                void *data) {
  ImPlot::SetupAxisFormat(axis, formatter, data);
}
CIMPLOT_API void ImPlot_SetupAxisTicks(ImAxis axis, const double *values,
                                       int n_ticks, const char *const *labels,
                                       bool keep_default) {
  ImPlot::SetupAxisTicks(axis, values, n_ticks, labels, keep_default);
}
CIMPLOT_API void ImPlot_SetupAxisTicksRange(ImAxis axis, double v_min,
                                            double v_max, int n_ticks,
                                            const char *const *labels,
                                            bool keep_default) {
  ImPlot::SetupAxisTicks(axis, v_min, v_max, n_ticks, labels, keep_default);
}
CIMPLOT_API void ImPlot_SetupAxisScale(ImAxis axis, ImPlotScale scale) {
  ImPlot::SetupAxisScale(axis, scale);
}
CIMPLOT_API void ImPlot_SetupAxisScaleTransform(ImAxis axis,
                                                ImPlotTransform forward,
                                                ImPlotTransform inverse,
                                                void *data = nullptr) {
  ImPlot::SetupAxisScale(axis, forward, inverse, data);
}
CIMPLOT_API void ImPlot_SetupAxisLimitsConstraints(ImAxis axis, double v_min,
                                                   double v_max) {
  ImPlot::SetupAxisLimitsConstraints(axis, v_min, v_max);
}
CIMPLOT_API void ImPlot_SetupAxisZoomConstraints(ImAxis axis, double v_min,
                                                 double v_max) {
  ImPlot::SetupAxisZoomConstraints(axis, v_min, v_max);
}
CIMPLOT_API void ImPlot_SetupAxes(const char *x_label, const char *y_label,
                                  ImPlotAxisFlags x_flags,
                                  ImPlotAxisFlags y_flags) {
  ImPlot::SetupAxes(x_label, y_label, x_flags, y_flags);
}
CIMPLOT_API void ImPlot_SetupAxesLimits(double x_min, double x_max,
                                        double y_min, double y_max,
                                        ImPlotCond cond) {
  ImPlot::SetupAxesLimits(x_min, x_max, y_min, y_max, cond);
}
CIMPLOT_API void ImPlot_SetupLegend(ImPlotLocation location,
                                    ImPlotLegendFlags flags) {
  ImPlot::SetupLegend(location, flags);
}
CIMPLOT_API void ImPlot_SetupMouseText(ImPlotLocation location,
                                       ImPlotMouseTextFlags flags = 0) {
  ImPlot::SetupMouseText(location, flags);
}
CIMPLOT_API void ImPlot_SetupFinish() { ImPlot::SetupFinish(); }
CIMPLOT_API void ImPlot_SetNextAxisLimits(ImAxis axis, double v_min,
                                          double v_max, ImPlotCond cond) {
  ImPlot::SetNextAxisLimits(axis, v_min, v_max, cond);
}
CIMPLOT_API void ImPlot_SetNextAxisLinks(ImAxis axis, double *link_min,
                                         double *link_max) {
  ImPlot::SetNextAxisLinks(axis, link_min, link_max);
}
CIMPLOT_API void ImPlot_SetNextAxisToFit(ImAxis axis) {
  ImPlot::SetNextAxisToFit(axis);
}
CIMPLOT_API void ImPlot_SetNextAxesLimits(double x_min, double x_max,
                                          double y_min, double y_max,
                                          ImPlotCond cond) {
  ImPlot::SetNextAxesLimits(x_min, x_max, y_min, y_max, cond);
}
CIMPLOT_API void ImPlot_SetNextAxesToFit() { ImPlot::SetNextAxesToFit(); }

CIMPLOT_API void ImPlot_PlotLine(ImGuiDataType dtype, const char *label_id,
                                 const void *values, int count,
                                 double xscale = 1, double xstart = 0,
                                 ImPlotLineFlags flags = 0, int offset = 0) {
  switch (dtype) {
  case ImGuiDataType_Float:
    ImPlot::PlotLine(label_id, (float *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  case ImGuiDataType_Double:
    ImPlot::PlotLine(label_id, (double *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  case ImGuiDataType_S8:
    ImPlot::PlotLine(label_id, (ImS8 *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  case ImGuiDataType_U8:
    ImPlot::PlotLine(label_id, (ImU8 *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  case ImGuiDataType_S16:
    ImPlot::PlotLine(label_id, (ImS16 *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  case ImGuiDataType_U16:
    ImPlot::PlotLine(label_id, (ImU16 *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  case ImGuiDataType_S32:
    ImPlot::PlotLine(label_id, (ImS32 *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  case ImGuiDataType_U32:
    ImPlot::PlotLine(label_id, (ImU32 *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  case ImGuiDataType_S64:
    ImPlot::PlotLine(label_id, (ImS64 *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  case ImGuiDataType_U64:
    ImPlot::PlotLine(label_id, (ImU64 *)(values), count, xscale, xstart, flags,
                     offset);
    break;
  }
}
CIMPLOT_API void ImPlot_PlotLine2D(ImGuiDataType dtype, const char *label_id,
                                 const void *xs, const void *ys, int count,
                                 ImPlotLineFlags flags = 0, int offset = 0) {
  switch (dtype) {
  case ImGuiDataType_Float:
    ImPlot::PlotLine(label_id, (float *)(xs), (float *)(ys), count, flags, offset);
    break;
  case ImGuiDataType_Double:
    ImPlot::PlotLine(label_id, (double *)(xs), (double *)(ys), count, flags, offset);
    break;
  case ImGuiDataType_S8:
    ImPlot::PlotLine(label_id, (ImS8 *)(xs), (ImS8 *)(ys), count, flags, offset);
    break;
  case ImGuiDataType_U8:
    ImPlot::PlotLine(label_id, (ImU8 *)(xs), (ImU8 *)(ys), count, flags, offset);
    break;
  case ImGuiDataType_S16:
    ImPlot::PlotLine(label_id, (ImS16 *)(xs), (ImS16 *)(ys), count, flags, offset);
    break;
  case ImGuiDataType_U16:
    ImPlot::PlotLine(label_id, (ImU16 *)(xs), (ImU16 *)(ys), count, flags, offset);
    break;
  case ImGuiDataType_S32:
    ImPlot::PlotLine(label_id, (ImS32 *)(xs), (ImS32 *)(ys), count, flags, offset);
    break;
  case ImGuiDataType_U32:
    ImPlot::PlotLine(label_id, (ImU32 *)(xs), (ImU32 *)(ys), count, flags, offset);
    break;
  case ImGuiDataType_S64:
    ImPlot::PlotLine(label_id, (ImS64 *)(xs), (ImS64 *)(ys), count, flags, offset);
    break;
  case ImGuiDataType_U64:
    ImPlot::PlotLine(label_id, (ImU64 *)(xs), (ImU64 *)(ys), count, flags, offset);
    break;

  }
}
CIMPLOT_API void ImPlot_PlotLineG(const char* label_id, ImPlotGetter getter, void* data, int count, ImPlotLineFlags flags){
    ImPlot::PlotLineG(label_id, getter, data, count, flags);
}
CIMPLOT_API void ImPlot_PlotScatter(ImGuiDataType dtype, const char* label_id, const void* values, int count, double xscale, double xstart, ImPlotScatterFlags flags, int offset){
    switch (dtype) {
    case ImGuiDataType_Float:
    ImPlot::PlotScatter(label_id,(float*)(values), count, xscale, xstart, flags, offset);
    break;
    case ImGuiDataType_Double:
    ImPlot::PlotScatter(label_id,(double*)(values), count, xscale, xstart, flags, offset);
    break;
    case ImGuiDataType_U8:
    ImPlot::PlotScatter(label_id,(ImU8*)(values), count, xscale, xstart, flags, offset);
    break;
    case ImGuiDataType_S8:
    ImPlot::PlotScatter(label_id,(ImS8*)(values), count, xscale, xstart, flags, offset);
    break;
    case ImGuiDataType_U16:
    ImPlot::PlotScatter(label_id,(ImU16*)(values), count, xscale, xstart, flags, offset);
    break;
    case ImGuiDataType_S16:
    ImPlot::PlotScatter(label_id,(ImS16*)(values), count, xscale, xstart, flags, offset);
    break;
    case ImGuiDataType_U32:
    ImPlot::PlotScatter(label_id,(ImU32*)(values), count, xscale, xstart, flags, offset);
    break;
    case ImGuiDataType_S32:
    ImPlot::PlotScatter(label_id,(ImS32*)(values), count, xscale, xstart, flags, offset);
    break;
    case ImGuiDataType_U64:
    ImPlot::PlotScatter(label_id,(ImU64*)(values), count, xscale, xstart, flags, offset);
    break;
    case ImGuiDataType_S64:
    ImPlot::PlotScatter(label_id,(ImS64*)(values), count, xscale, xstart, flags, offset);
    break;
    }
}
CIMPLOT_API void ImPlot_PlotScatter2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, ImPlotScatterFlags flags, int offset){
    switch (dtype) {
    case ImGuiDataType_Float:
    ImPlot::PlotScatter(label_id, (float*)(xs), (float*)(ys), count, flags, offset);
    break;
    case ImGuiDataType_Double:
    ImPlot::PlotScatter(label_id, (double*)(xs), (double*)(ys), count, flags, offset);
    break;
    case ImGuiDataType_U8:
    ImPlot::PlotScatter(label_id, (ImU8*)(xs), (ImU8*)(ys), count, flags, offset);
    break;
    case ImGuiDataType_S8:
    ImPlot::PlotScatter(label_id, (ImS8*)(xs), (ImS8*)(ys), count, flags, offset);
    break;
    case ImGuiDataType_U16:
    ImPlot::PlotScatter(label_id, (ImU16*)(xs), (ImU16*)(ys), count, flags, offset);
    break;
    case ImGuiDataType_S16:
    ImPlot::PlotScatter(label_id, (ImS16*)(xs), (ImS16*)(ys), count, flags, offset);
    break;
    case ImGuiDataType_U32:
    ImPlot::PlotScatter(label_id, (ImU32*)(xs), (ImU32*)(ys), count, flags, offset);
    break;
    case ImGuiDataType_S32:
    ImPlot::PlotScatter(label_id, (ImS32*)(xs), (ImS32*)(ys), count, flags, offset);
    break;
    case ImGuiDataType_U64:
    ImPlot::PlotScatter(label_id, (ImU64*)(xs), (ImU64*)(ys), count, flags, offset);
    break;
    case ImGuiDataType_S64:
    ImPlot::PlotScatter(label_id, (ImS64*)(xs), (ImS64*)(ys), count, flags, offset);
    break;
    }
}
CIMPLOT_API void ImPlot_PlotScatterG(const char* label_id, ImPlotGetter getter, void* data, int count, ImPlotScatterFlags flags) {
    ImPlot::PlotScatterG(label_id, getter, data, count, flags);
}

CIMPLOT_API void ImPlot_PlotStairs(ImGuiDataType dtype, const char* label_id, const void* values, int count, double xscale, double xstart, ImPlotStairsFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotStairs(label_id, (float*)values, count, xscale, xstart, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotStairs(label_id, (double*)values, count, xscale, xstart, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotStairs(label_id, (ImS8*)values, count, xscale, xstart, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotStairs(label_id, (ImU8*)values, count, xscale, xstart, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotStairs(label_id, (ImS16*)values, count, xscale, xstart, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotStairs(label_id, (ImU16*)values, count, xscale, xstart, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotStairs(label_id, (ImS32*)values, count, xscale, xstart, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotStairs(label_id, (ImU32*)values, count, xscale, xstart, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotStairs(label_id, (ImS64*)values, count, xscale, xstart, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotStairs(label_id, (ImU64*)values, count, xscale, xstart, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotStairs2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, ImPlotStairsFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotStairs(label_id, (float*)xs, (float*)ys, count, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotStairs(label_id, (double*)xs, (double*)ys, count, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotStairs(label_id, (ImS8*)xs, (ImS8*)ys, count, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotStairs(label_id, (ImU8*)xs, (ImU8*)ys, count, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotStairs(label_id, (ImS16*)xs, (ImS16*)ys, count, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotStairs(label_id, (ImU16*)xs, (ImU16*)ys, count, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotStairs(label_id, (ImS32*)xs, (ImS32*)ys, count, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotStairs(label_id, (ImU32*)xs, (ImU32*)ys, count, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotStairs(label_id, (ImS64*)xs, (ImS64*)ys, count, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotStairs(label_id, (ImU64*)xs, (ImU64*)ys, count, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotStairsG(const char* label_id, ImPlotGetter getter, void* data, int count, ImPlotStairsFlags flags) {
    ImPlot::PlotStairsG(label_id, getter, data, count, flags);
}
CIMPLOT_API void ImPlot_PlotShaded(ImGuiDataType dtype, const char* label_id, const void* values, int count, double yref, double xscale, double xstart, ImPlotShadedFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotShaded(label_id, (float*)values, count, yref, xscale, xstart, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotShaded(label_id, (double*)values, count, yref, xscale, xstart, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotShaded(label_id, (ImS8*)values, count, yref, xscale, xstart, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotShaded(label_id, (ImU8*)values, count, yref, xscale, xstart, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotShaded(label_id, (ImS16*)values, count, yref, xscale, xstart, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotShaded(label_id, (ImU16*)values, count, yref, xscale, xstart, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotShaded(label_id, (ImS32*)values, count, yref, xscale, xstart, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotShaded(label_id, (ImU32*)values, count, yref, xscale, xstart, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotShaded(label_id, (ImS64*)values, count, yref, xscale, xstart, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotShaded(label_id, (ImU64*)values, count, yref, xscale, xstart, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotShaded2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, double yref, ImPlotShadedFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotShaded(label_id, (float*)xs, (float*)ys, count, yref, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotShaded(label_id, (double*)xs, (double*)ys, count, yref, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotShaded(label_id, (ImS8*)xs, (ImS8*)ys, count, yref, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotShaded(label_id, (ImU8*)xs, (ImU8*)ys, count, yref, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotShaded(label_id, (ImS16*)xs, (ImS16*)ys, count, yref, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotShaded(label_id, (ImU16*)xs, (ImU16*)ys, count, yref, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotShaded(label_id, (ImS32*)xs, (ImS32*)ys, count, yref, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotShaded(label_id, (ImU32*)xs, (ImU32*)ys, count, yref, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotShaded(label_id, (ImS64*)xs, (ImS64*)ys, count, yref, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotShaded(label_id, (ImU64*)xs, (ImU64*)ys, count, yref, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotShaded2Y(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys1, const void* ys2, int count, ImPlotShadedFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotShaded(label_id, (float*)xs, (float*)ys1, (float*)ys2, count, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotShaded(label_id, (double*)xs, (double*)ys1, (double*)ys2, count, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotShaded(label_id, (ImS8*)xs, (ImS8*)ys1, (ImS8*)ys2, count, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotShaded(label_id, (ImU8*)xs, (ImU8*)ys1, (ImU8*)ys2, count, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotShaded(label_id, (ImS16*)xs, (ImS16*)ys1, (ImS16*)ys2, count, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotShaded(label_id, (ImU16*)xs, (ImU16*)ys1, (ImU16*)ys2, count, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotShaded(label_id, (ImS32*)xs, (ImS32*)ys1, (ImS32*)ys2, count, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotShaded(label_id, (ImU32*)xs, (ImU32*)ys1, (ImU32*)ys2, count, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotShaded(label_id, (ImS64*)xs, (ImS64*)ys1, (ImS64*)ys2, count, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotShaded(label_id, (ImU64*)xs, (ImU64*)ys1, (ImU64*)ys2, count, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotShadedG(const char* label_id, ImPlotGetter getter1, void* data1, ImPlotGetter getter2, void* data2, int count, ImPlotShadedFlags flags) {
    ImPlot::PlotShadedG(label_id, getter1, data1, getter2, data2, count, flags);
}


CIMPLOT_API void ImPlot_PlotBars(ImGuiDataType dtype, const char* label_id, const void* values, int count, double bar_size, double shift, ImPlotBarsFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotBars(label_id, (float*)values, count, bar_size, shift, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotBars(label_id, (double*)values, count, bar_size, shift, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotBars(label_id, (ImS8*)values, count, bar_size, shift, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotBars(label_id, (ImU8*)values, count, bar_size, shift, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotBars(label_id, (ImS16*)values, count, bar_size, shift, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotBars(label_id, (ImU16*)values, count, bar_size, shift, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotBars(label_id, (ImS32*)values, count, bar_size, shift, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotBars(label_id, (ImU32*)values, count, bar_size, shift, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotBars(label_id, (ImS64*)values, count, bar_size, shift, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotBars(label_id, (ImU64*)values, count, bar_size, shift, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotBars2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, double bar_size, ImPlotBarsFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotBars(label_id, (float*)xs, (float*)ys, count, bar_size, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotBars(label_id, (double*)xs, (double*)ys, count, bar_size, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotBars(label_id, (ImS8*)xs, (ImS8*)ys, count, bar_size, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotBars(label_id, (ImU8*)xs, (ImU8*)ys, count, bar_size, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotBars(label_id, (ImS16*)xs, (ImS16*)ys, count, bar_size, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotBars(label_id, (ImU16*)xs, (ImU16*)ys, count, bar_size, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotBars(label_id, (ImS32*)xs, (ImS32*)ys, count, bar_size, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotBars(label_id, (ImU32*)xs, (ImU32*)ys, count, bar_size, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotBars(label_id, (ImS64*)xs, (ImS64*)ys, count, bar_size, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotBars(label_id, (ImU64*)xs, (ImU64*)ys, count, bar_size, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotBarsG(const char* label_id, ImPlotGetter getter, void* data, int count, double bar_size, ImPlotBarsFlags flags) {
    ImPlot::PlotBarsG(label_id, getter, data, count, bar_size, flags);
}
CIMPLOT_API void ImPlot_PlotBarGroups(ImGuiDataType dtype, const char** const label_ids, const void* values, int item_count, int group_count, double group_size, double shift, ImPlotBarGroupsFlags flags) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotBarGroups(label_ids, (float*)values, item_count, group_count, group_size, shift, flags);
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotBarGroups(label_ids, (double*)values, item_count, group_count, group_size, shift, flags);
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotBarGroups(label_ids, (ImS8*)values, item_count, group_count, group_size, shift, flags);
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotBarGroups(label_ids, (ImU8*)values, item_count, group_count, group_size, shift, flags);
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotBarGroups(label_ids, (ImS16*)values, item_count, group_count, group_size, shift, flags);
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotBarGroups(label_ids, (ImU16*)values, item_count, group_count, group_size, shift, flags);
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotBarGroups(label_ids, (ImS32*)values, item_count, group_count, group_size, shift, flags);
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotBarGroups(label_ids, (ImU32*)values, item_count, group_count, group_size, shift, flags);
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotBarGroups(label_ids, (ImS64*)values, item_count, group_count, group_size, shift, flags);
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotBarGroups(label_ids, (ImU64*)values, item_count, group_count, group_size, shift, flags);
        break;
    }
}
CIMPLOT_API void ImPlot_PlotErrorBars(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, const void* err, int count, ImPlotErrorBarsFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotErrorBars(label_id, (float*)xs, (float*)ys, (float*)err, count, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotErrorBars(label_id, (double*)xs, (double*)ys, (double*)err, count, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotErrorBars(label_id, (ImS8*)xs, (ImS8*)ys, (ImS8*)err, count, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotErrorBars(label_id, (ImU8*)xs, (ImU8*)ys, (ImU8*)err, count, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotErrorBars(label_id, (ImS16*)xs, (ImS16*)ys, (ImS16*)err, count, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotErrorBars(label_id, (ImU16*)xs, (ImU16*)ys, (ImU16*)err, count, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotErrorBars(label_id, (ImS32*)xs, (ImS32*)ys, (ImS32*)err, count, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotErrorBars(label_id, (ImU32*)xs, (ImU32*)ys, (ImU32*)err, count, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotErrorBars(label_id, (ImS64*)xs, (ImS64*)ys, (ImS64*)err, count, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotErrorBars(label_id, (ImU64*)xs, (ImU64*)ys, (ImU64*)err, count, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotErrorBarsNeg(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, const void* neg, const void* pos, int count, ImPlotErrorBarsFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotErrorBars(label_id, (float*)xs, (float*)ys, (float*)neg, (float*)pos, count, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotErrorBars(label_id, (double*)xs, (double*)ys, (double*)neg, (double*)pos, count, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotErrorBars(label_id, (ImS8*)xs, (ImS8*)ys, (ImS8*)neg, (ImS8*)pos, count, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotErrorBars(label_id, (ImU8*)xs, (ImU8*)ys, (ImU8*)neg, (ImU8*)pos, count, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotErrorBars(label_id, (ImS16*)xs, (ImS16*)ys, (ImS16*)neg, (ImS16*)pos, count, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotErrorBars(label_id, (ImU16*)xs, (ImU16*)ys, (ImU16*)neg, (ImU16*)pos, count, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotErrorBars(label_id, (ImS32*)xs, (ImS32*)ys, (ImS32*)neg, (ImS32*)pos, count, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotErrorBars(label_id, (ImU32*)xs, (ImU32*)ys, (ImU32*)neg, (ImU32*)pos, count, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotErrorBars(label_id, (ImS64*)xs, (ImS64*)ys, (ImS64*)neg, (ImS64*)pos, count, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotErrorBars(label_id, (ImU64*)xs, (ImU64*)ys, (ImU64*)neg, (ImU64*)pos, count, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotStems(ImGuiDataType dtype, const char* label_id, const void* values, int count, double ref, double scale, double start, ImPlotStemsFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotStems(label_id, (float*)values, count, ref, scale, start, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotStems(label_id, (double*)values, count, ref, scale, start, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotStems(label_id, (ImS8*)values, count, ref, scale, start, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotStems(label_id, (ImU8*)values, count, ref, scale, start, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotStems(label_id, (ImS16*)values, count, ref, scale, start, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotStems(label_id, (ImU16*)values, count, ref, scale, start, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotStems(label_id, (ImS32*)values, count, ref, scale, start, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotStems(label_id, (ImU32*)values, count, ref, scale, start, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotStems(label_id, (ImS64*)values, count, ref, scale, start, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotStems(label_id, (ImU64*)values, count, ref, scale, start, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotStems2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, double ref, ImPlotStemsFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotStems(label_id, (float*)xs, (float*)ys, count, ref, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotStems(label_id, (double*)xs, (double*)ys, count, ref, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotStems(label_id, (ImS8*)xs, (ImS8*)ys, count, ref, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotStems(label_id, (ImU8*)xs, (ImU8*)ys, count, ref, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotStems(label_id, (ImS16*)xs, (ImS16*)ys, count, ref, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotStems(label_id, (ImU16*)xs, (ImU16*)ys, count, ref, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotStems(label_id, (ImS32*)xs, (ImS32*)ys, count, ref, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotStems(label_id, (ImU32*)xs, (ImU32*)ys, count, ref, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotStems(label_id, (ImS64*)xs, (ImS64*)ys, count, ref, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotStems(label_id, (ImU64*)xs, (ImU64*)ys, count, ref, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotInfLines(ImGuiDataType dtype, const char* label_id, const void* values, int count, ImPlotInfLinesFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotInfLines(label_id, (float*)values, count, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotInfLines(label_id, (double*)values, count, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotInfLines(label_id, (ImS8*)values, count, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotInfLines(label_id, (ImU8*)values, count, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotInfLines(label_id, (ImS16*)values, count, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotInfLines(label_id, (ImU16*)values, count, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotInfLines(label_id, (ImS32*)values, count, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotInfLines(label_id, (ImU32*)values, count, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotInfLines(label_id, (ImS64*)values, count, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotInfLines(label_id, (ImU64*)values, count, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotPieChart_Fmt(ImGuiDataType dtype, const char* const* label_ids, const void* values, int count, double x, double y, double radius, ImPlotFormatter fmt, void* fmt_data, double angle0, ImPlotPieChartFlags flags) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotPieChart(label_ids, (float*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotPieChart(label_ids, (double*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotPieChart(label_ids, (ImS8*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotPieChart(label_ids, (ImU8*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotPieChart(label_ids, (ImS16*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotPieChart(label_ids, (ImU16*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotPieChart(label_ids, (ImS32*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotPieChart(label_ids, (ImU32*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotPieChart(label_ids, (ImS64*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotPieChart(label_ids, (ImU64*)values, count, x, y, radius, fmt, fmt_data, angle0, flags);
        break;
    }
}
CIMPLOT_API void ImPlot_PlotPieChart(ImGuiDataType dtype, const char* const* label_ids, const void* values, int count, double x, double y, double radius, const char* label_fmt, double angle0, ImPlotPieChartFlags flags) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotPieChart(label_ids, (float*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotPieChart(label_ids, (double*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotPieChart(label_ids, (ImS8*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotPieChart(label_ids, (ImU8*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotPieChart(label_ids, (ImS16*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotPieChart(label_ids, (ImU16*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotPieChart(label_ids, (ImS32*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotPieChart(label_ids, (ImU32*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotPieChart(label_ids, (ImS64*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotPieChart(label_ids, (ImU64*)values, count, x, y, radius, label_fmt, angle0, flags);
        break;
    }
}
CIMPLOT_API void ImPlot_PlotHeatmap(ImGuiDataType dtype, const char* label_id, const void* values, int rows, int cols, double scale_min, double scale_max, const char* label_fmt, const ImPlotPoint bounds_min, const ImPlotPoint bounds_max, ImPlotHeatmapFlags flags) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotHeatmap(label_id, (float*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotHeatmap(label_id, (double*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotHeatmap(label_id, (ImS8*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotHeatmap(label_id, (ImU8*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotHeatmap(label_id, (ImS16*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotHeatmap(label_id, (ImU16*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotHeatmap(label_id, (ImS32*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotHeatmap(label_id, (ImU32*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotHeatmap(label_id, (ImS64*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotHeatmap(label_id, (ImU64*)values, rows, cols, scale_min, scale_max, label_fmt, bounds_min, bounds_max, flags);
        break;
    }
}
CIMPLOT_API double ImPlot_PlotHistogram(ImGuiDataType dtype, const char* label_id, const void* values, int count, int bins, double bar_scale, ImPlotRange range, ImPlotHistogramFlags flags) {
    switch (dtype) {
    case ImGuiDataType_Float:
        return ImPlot::PlotHistogram(label_id, (float*)values, count, bins, bar_scale, range, flags);
    case ImGuiDataType_Double:
        return ImPlot::PlotHistogram(label_id, (double*)values, count, bins, bar_scale, range, flags);
    case ImGuiDataType_S8:
        return ImPlot::PlotHistogram(label_id, (ImS8*)values, count, bins, bar_scale, range, flags);
    case ImGuiDataType_U8:
        return ImPlot::PlotHistogram(label_id, (ImU8*)values, count, bins, bar_scale, range, flags);
    case ImGuiDataType_S16:
        return ImPlot::PlotHistogram(label_id, (ImS16*)values, count, bins, bar_scale, range, flags);
    case ImGuiDataType_U16:
        return ImPlot::PlotHistogram(label_id, (ImU16*)values, count, bins, bar_scale, range, flags);
    case ImGuiDataType_S32:
        return ImPlot::PlotHistogram(label_id, (ImS32*)values, count, bins, bar_scale, range, flags);
    case ImGuiDataType_U32:
        return ImPlot::PlotHistogram(label_id, (ImU32*)values, count, bins, bar_scale, range, flags);
    case ImGuiDataType_S64:
        return ImPlot::PlotHistogram(label_id, (ImS64*)values, count, bins, bar_scale, range, flags);
    case ImGuiDataType_U64:
        return ImPlot::PlotHistogram(label_id, (ImU64*)values, count, bins, bar_scale, range, flags);
    default:
        return 0.0;
    }
}
CIMPLOT_API double ImPlot_PlotHistogram2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, int x_bins, int y_bins, ImPlotRect range, ImPlotHistogramFlags flags) {
    switch (dtype) {
    case ImGuiDataType_Float:
        return ImPlot::PlotHistogram2D(label_id, (float*)xs, (float*)ys, count, x_bins, y_bins, range, flags);
    case ImGuiDataType_Double:
        return ImPlot::PlotHistogram2D(label_id, (double*)xs, (double*)ys, count, x_bins, y_bins, range, flags);
    case ImGuiDataType_S8:
        return ImPlot::PlotHistogram2D(label_id, (ImS8*)xs, (ImS8*)ys, count, x_bins, y_bins, range, flags);
    case ImGuiDataType_U8:
        return ImPlot::PlotHistogram2D(label_id, (ImU8*)xs, (ImU8*)ys, count, x_bins, y_bins, range, flags);
    case ImGuiDataType_S16:
        return ImPlot::PlotHistogram2D(label_id, (ImS16*)xs, (ImS16*)ys, count, x_bins, y_bins, range, flags);
    case ImGuiDataType_U16:
        return ImPlot::PlotHistogram2D(label_id, (ImU16*)xs, (ImU16*)ys, count, x_bins, y_bins, range, flags);
    case ImGuiDataType_S32:
        return ImPlot::PlotHistogram2D(label_id, (ImS32*)xs, (ImS32*)ys, count, x_bins, y_bins, range, flags);
    case ImGuiDataType_U32:
        return ImPlot::PlotHistogram2D(label_id, (ImU32*)xs, (ImU32*)ys, count, x_bins, y_bins, range, flags);
    case ImGuiDataType_S64:
        return ImPlot::PlotHistogram2D(label_id, (ImS64*)xs, (ImS64*)ys, count, x_bins, y_bins, range, flags);
    case ImGuiDataType_U64:
        return ImPlot::PlotHistogram2D(label_id, (ImU64*)xs, (ImU64*)ys, count, x_bins, y_bins, range, flags);
    default:
        return 0.0;
    }
}
CIMPLOT_API void ImPlot_PlotDigital(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, ImPlotDigitalFlags flags, int offset) {
    switch (dtype) {
    case ImGuiDataType_Float:
        ImPlot::PlotDigital(label_id, (float*)xs, (float*)ys, count, flags, offset, sizeof(float));
        break;
    case ImGuiDataType_Double:
        ImPlot::PlotDigital(label_id, (double*)xs, (double*)ys, count, flags, offset, sizeof(double));
        break;
    case ImGuiDataType_S8:
        ImPlot::PlotDigital(label_id, (ImS8*)xs, (ImS8*)ys, count, flags, offset, sizeof(ImS8));
        break;
    case ImGuiDataType_U8:
        ImPlot::PlotDigital(label_id, (ImU8*)xs, (ImU8*)ys, count, flags, offset, sizeof(ImU8));
        break;
    case ImGuiDataType_S16:
        ImPlot::PlotDigital(label_id, (ImS16*)xs, (ImS16*)ys, count, flags, offset, sizeof(ImS16));
        break;
    case ImGuiDataType_U16:
        ImPlot::PlotDigital(label_id, (ImU16*)xs, (ImU16*)ys, count, flags, offset, sizeof(ImU16));
        break;
    case ImGuiDataType_S32:
        ImPlot::PlotDigital(label_id, (ImS32*)xs, (ImS32*)ys, count, flags, offset, sizeof(ImS32));
        break;
    case ImGuiDataType_U32:
        ImPlot::PlotDigital(label_id, (ImU32*)xs, (ImU32*)ys, count, flags, offset, sizeof(ImU32));
        break;
    case ImGuiDataType_S64:
        ImPlot::PlotDigital(label_id, (ImS64*)xs, (ImS64*)ys, count, flags, offset, sizeof(ImS64));
        break;
    case ImGuiDataType_U64:
        ImPlot::PlotDigital(label_id, (ImU64*)xs, (ImU64*)ys, count, flags, offset, sizeof(ImU64));
        break;
    }
}
CIMPLOT_API void ImPlot_PlotDigitalG(const char* label_id, ImPlotGetter getter, void* data, int count, ImPlotDigitalFlags flags) {
    ImPlot::PlotDigitalG(label_id, getter, data, count, flags);
}
// #ifdef IMGUI_HAS_TEXTURES
CIMPLOT_API void ImPlot_PlotImage(const char* label_id, ImTextureRef tex_ref, const ImPlotPoint bounds_min, const ImPlotPoint bounds_max, const ImVec2 uv0, const ImVec2 uv1, const ImVec4 tint_col, ImPlotImageFlags flags) {
    ImPlot::PlotImage(label_id, tex_ref, bounds_min, bounds_max, uv0, uv1, tint_col, flags);
}
// #else
// CIMPLOT_API void ImPlot_PlotImage(const char* label_id, ImTextureID tex_ref, const ImPlotPoint bounds_min, const ImPlotPoint bounds_max, const ImVec2 uv0, const ImVec2 uv1, const ImVec4 tint_col, ImPlotImageFlags flags) {
//     ImPlot::PlotImage(label_id, tex_ref, bounds_min, bounds_max, uv0, uv1, tint_col, flags);
// }
// #endif
CIMPLOT_API void ImPlot_PlotText(const char* text, double x, double y, const ImVec2 pix_offset, ImPlotTextFlags flags) {
    ImPlot::PlotText(text, x, y, pix_offset, flags);
}
CIMPLOT_API void ImPlot_PlotDummy(const char* label_id, ImPlotDummyFlags flags) {
    ImPlot::PlotDummy(label_id, flags);
}

CIMPLOT_API bool ImPlot_DragPoint(int id, double* x, double* y, const ImVec4 col, float size, ImPlotDragToolFlags flags, bool* out_clicked, bool* out_hovered, bool* held) {
    return ImPlot::DragPoint(id, x, y, col, size, flags, out_clicked, out_hovered, held);
}
CIMPLOT_API bool ImPlot_DragLineX(int id, double* x, const ImVec4 col, float thickness, ImPlotDragToolFlags flags, bool* out_clicked, bool* out_hovered, bool* held) {
    return ImPlot::DragLineX(id, x, col, thickness, flags, out_clicked, out_hovered, held);
}
CIMPLOT_API bool ImPlot_DragLineY(int id, double* y, const ImVec4 col, float thickness, ImPlotDragToolFlags flags, bool* out_clicked, bool* out_hovered, bool* held) {
    return ImPlot::DragLineY(id, y, col, thickness, flags, out_clicked, out_hovered, held);
}
CIMPLOT_API bool ImPlot_DragRect(int id, double* x1, double* y1, double* x2, double* y2, const ImVec4 col, ImPlotDragToolFlags flags, bool* out_clicked, bool* out_hovered, bool* held) {
    return ImPlot::DragRect(id, x1, y1, x2, y2, col, flags, out_clicked, out_hovered, held);
}

CIMPLOT_API void ImPlot_Annotation_Round(double x, double y, const ImVec4 col, const ImVec2 pix_offset, bool clamp, bool round) {
    ImPlot::Annotation(x, y, col, pix_offset, clamp, round);
}
CIMPLOT_API void ImPlot_Annotation(double x, double y, const ImVec4 col, const ImVec2 pix_offset, bool clamp, const char* text) {
    ImPlot::Annotation(x, y, col, pix_offset, clamp,"%s", text);
}
CIMPLOT_API void ImPlot_Annotation_Fmt(double x, double y, const ImVec4 col, const ImVec2 pix_offset, bool clamp, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImPlot::Annotation(x, y, col, pix_offset, clamp, fmt, args);
    va_end(args);
}

CIMPLOT_API void ImPlot_TagX(double x, const ImVec4 col, bool round) {
    ImPlot::TagX(x, col, round);
}
CIMPLOT_API void ImPlot_TagX_Fmt(double x, const ImVec4 col, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImPlot::TagX(x, col, fmt, args);
    va_end(args);
}

CIMPLOT_API void ImPlot_TagY(double y, const ImVec4 col, bool round) {
    ImPlot::TagY(y, col, round);
}
CIMPLOT_API void ImPlot_TagY_Fmt(double y, const ImVec4 col, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImPlot::TagY(y, col, fmt, args);
    va_end(args);
}
CIMPLOT_API void ImPlot_SetAxis(ImAxis axis) { ImPlot::SetAxis(axis);}
CIMPLOT_API void ImPlot_SetAxes(ImAxis x_axis, ImAxis y_axis) { ImPlot::SetAxes(x_axis, y_axis);}
CIMPLOT_API CImPlotPoint ImPlot_PixelsToPlot(const ImVec2 pix, ImAxis x_axis, ImAxis y_axis) {
    auto p= ImPlot::PixelsToPlot(pix, x_axis, y_axis);
    return CImPlotPoint{p.x,p.y};
}
CIMPLOT_API CImPlotPoint ImPlot_PixelsToPlotXY(float x, float y, ImAxis x_axis, ImAxis y_axis) {
    auto p= ImPlot::PixelsToPlot(x, y, x_axis, y_axis);
    return CImPlotPoint{p.x,p.y};
}
CIMPLOT_API CImVec2 ImPlot_PlotToPixels(const ImPlotPoint plt, ImAxis x_axis, ImAxis y_axis) {
    auto vec = ImPlot::PlotToPixels(plt, x_axis, y_axis);
    return CImVec2{vec.x,vec.y};
}
CIMPLOT_API CImVec2 ImPlot_PlotToPixelsXY(double x, double y, ImAxis x_axis, ImAxis y_axis) {
    auto vec =  ImPlot::PlotToPixels(x, y, x_axis, y_axis);
    return CImVec2{vec.x,vec.y};
}
CIMPLOT_API CImVec2 ImPlot_GetPlotPos() {  auto vec = ImPlot::GetPlotPos(); return CImVec2{vec.x,vec.y};}
CIMPLOT_API CImVec2 ImPlot_GetPlotSize() {   auto vec = ImPlot::GetPlotSize(); return CImVec2{vec.x,vec.y};}
CIMPLOT_API CImPlotPoint ImPlot_GetPlotMousePos(ImAxis x_axis, ImAxis y_axis) {
    auto p=  ImPlot::GetPlotMousePos(x_axis, y_axis);
    return CImPlotPoint{p.x,p.y};
}
CIMPLOT_API CImPlotRect ImPlot_GetPlotLimits(ImAxis x_axis, ImAxis y_axis) {
    auto rct = ImPlot::GetPlotLimits(x_axis, y_axis);
    return  CImPlotRect{CImPlotRange{rct.X.Min,rct.X.Max}, CImPlotRange{rct.Y.Min,rct.Y.Max}};
}
CIMPLOT_API bool ImPlot_IsPlotHovered() {
    return ImPlot::IsPlotHovered();
}
CIMPLOT_API bool ImPlot_IsAxisHovered(ImAxis axis) {
    return ImPlot::IsAxisHovered(axis);
}
CIMPLOT_API bool ImPlot_IsSubplotsHovered() {
    return ImPlot::IsSubplotsHovered();
}
CIMPLOT_API bool ImPlot_IsPlotSelected() {
    return ImPlot::IsPlotSelected();
}
CIMPLOT_API CImPlotRect ImPlot_GetPlotSelection(ImAxis x_axis, ImAxis y_axis) {
    auto rct =  ImPlot::GetPlotSelection(x_axis, y_axis);
    return  CImPlotRect{CImPlotRange{rct.X.Min,rct.X.Max}, CImPlotRange{rct.Y.Min,rct.Y.Max}};
}
CIMPLOT_API void ImPlot_CancelPlotSelection() {
    ImPlot::CancelPlotSelection();
}
CIMPLOT_API void ImPlot_HideNextItem(bool hidden, ImPlotCond cond) {
    ImPlot::HideNextItem(hidden, cond);
}
CIMPLOT_API bool ImPlot_BeginAlignedPlots(const char* group_id, bool vertical) {
    return ImPlot::BeginAlignedPlots(group_id, vertical);
}
CIMPLOT_API void ImPlot_EndAlignedPlots() {
    ImPlot::EndAlignedPlots();
}

CIMPLOT_API bool ImPlot_BeginLegendPopup(const char* label_id, ImGuiMouseButton mouse_button) {
    return ImPlot::BeginLegendPopup(label_id, mouse_button);
}
CIMPLOT_API void ImPlot_EndLegendPopup() {
    ImPlot::EndLegendPopup();
}
CIMPLOT_API bool ImPlot_IsLegendEntryHovered(const char* label_id) {
    return ImPlot::IsLegendEntryHovered(label_id);
}
CIMPLOT_API bool ImPlot_BeginDragDropTargetPlot() {
    return ImPlot::BeginDragDropTargetPlot();
}
CIMPLOT_API bool ImPlot_BeginDragDropTargetAxis(ImAxis axis) {
    return ImPlot::BeginDragDropTargetAxis(axis);
}
CIMPLOT_API bool ImPlot_BeginDragDropTargetLegend() {
    return ImPlot::BeginDragDropTargetLegend();
}
CIMPLOT_API void ImPlot_EndDragDropTarget() {
    ImPlot::EndDragDropTarget();
}
CIMPLOT_API bool ImPlot_BeginDragDropSourcePlot(ImGuiDragDropFlags flags) {
    return ImPlot::BeginDragDropSourcePlot(flags);
}
CIMPLOT_API bool ImPlot_BeginDragDropSourceAxis(ImAxis axis, ImGuiDragDropFlags flags) {
    return ImPlot::BeginDragDropSourceAxis(axis, flags);
}
CIMPLOT_API bool ImPlot_BeginDragDropSourceItem(const char* label_id, ImGuiDragDropFlags flags) {
    return ImPlot::BeginDragDropSourceItem(label_id, flags);
}
CIMPLOT_API void ImPlot_EndDragDropSource() {
    ImPlot::EndDragDropSource();
}

CIMPLOT_API ImPlotStyle* ImPlot_GetStyle() {
    return &ImPlot::GetStyle();
}
CIMPLOT_API void ImPlot_StyleColorsAuto(ImPlotStyle* dst) {
    ImPlot::StyleColorsAuto(dst);
}
CIMPLOT_API void ImPlot_StyleColorsClassic(ImPlotStyle* dst) {
    ImPlot::StyleColorsClassic(dst);
}
CIMPLOT_API void ImPlot_StyleColorsDark(ImPlotStyle* dst) {
    ImPlot::StyleColorsDark(dst);
}
CIMPLOT_API void ImPlot_StyleColorsLight(ImPlotStyle* dst) {
    ImPlot::StyleColorsLight(dst);
}
CIMPLOT_API void ImPlot_PushStyleColor_ImU32(ImPlotCol idx, ImU32 col) {
    ImPlot::PushStyleColor(idx, col);
}
CIMPLOT_API void ImPlot_PushStyleColor_ImVec4(ImPlotCol idx, const ImVec4 col) {
    ImPlot::PushStyleColor(idx, col);
}
CIMPLOT_API void ImPlot_PopStyleColor(int count) {
    ImPlot::PopStyleColor(count);
}
CIMPLOT_API void ImPlot_PushStyleVar_Float(ImPlotStyleVar idx, float val) {
    ImPlot::PushStyleVar(idx, val);
}
CIMPLOT_API void ImPlot_PushStyleVar_Int(ImPlotStyleVar idx, int val) {
    ImPlot::PushStyleVar(idx, val);
}
CIMPLOT_API void ImPlot_PushStyleVar_ImVec2(ImPlotStyleVar idx, const ImVec2 val) {
    ImPlot::PushStyleVar(idx, val);
}
CIMPLOT_API void ImPlot_PopStyleVar(int count) {
    ImPlot::PopStyleVar(count);
}
CIMPLOT_API void ImPlot_SetNextLineStyle(const ImVec4 col, float weight) {
    ImPlot::SetNextLineStyle(col, weight);
}
CIMPLOT_API void ImPlot_SetNextFillStyle(const ImVec4 col, float alpha_mod) {
    ImPlot::SetNextFillStyle(col, alpha_mod);
}
CIMPLOT_API void ImPlot_SetNextMarkerStyle(ImPlotMarker marker, float size, const ImVec4 fill, float weight, const ImVec4 outline) {
    ImPlot::SetNextMarkerStyle(marker, size, fill, weight, outline);
}
CIMPLOT_API void ImPlot_SetNextErrorBarStyle(const ImVec4 col, float size, float weight) {
    ImPlot::SetNextErrorBarStyle(col, size, weight);
}
CIMPLOT_API CImVec4 ImPlot_GetLastItemColor() {
    auto v4 = ImPlot::GetLastItemColor();
    return  CImVec4{v4.x,v4.y,v4.z, v4.w};
}
CIMPLOT_API const char* ImPlot_GetStyleColorName(ImPlotCol idx) {
    return ImPlot::GetStyleColorName(idx);
}
CIMPLOT_API const char* ImPlot_GetMarkerName(ImPlotMarker idx) {
    return ImPlot::GetMarkerName(idx);
}
CIMPLOT_API ImPlotColormap ImPlot_AddColormap_ImVec4(const char* name, const ImVec4* cols, int size, bool qual) {
    return ImPlot::AddColormap(name, cols, size, qual);
}
CIMPLOT_API ImPlotColormap ImPlot_AddColormap_ImU32(const char* name, const ImU32* cols, int size, bool qual) {
    return ImPlot::AddColormap(name, cols, size, qual);
}
CIMPLOT_API int ImPlot_GetColormapCount() { return ImPlot::GetColormapCount();}
CIMPLOT_API const char* ImPlot_GetColormapName(ImPlotColormap cmap) {
    return ImPlot::GetColormapName(cmap);
}
CIMPLOT_API ImPlotColormap ImPlot_GetColormapIndex(const char* name) {
    return ImPlot::GetColormapIndex(name);
}
CIMPLOT_API void ImPlot_PushColormap_Index(ImPlotColormap cmap) {
    ImPlot::PushColormap(cmap);
}
CIMPLOT_API void ImPlot_PushColormap_Name(const char* name) {
    ImPlot::PushColormap(name);
}

CIMPLOT_API void ImPlot_PopColormap(int count) {
    ImPlot::PopColormap(count);
}
CIMPLOT_API CImVec4 ImPlot_NextColormapColor() {
    auto v4 = ImPlot::NextColormapColor();
    return CImVec4{v4.x, v4.y, v4.z, v4.w};
}
CIMPLOT_API int ImPlot_GetColormapSize(ImPlotColormap cmap) {
    return ImPlot::GetColormapSize(cmap);
}
CIMPLOT_API CImVec4 ImPlot_GetColormapColor(int idx, ImPlotColormap cmap) {
    auto v4 = ImPlot::GetColormapColor(idx, cmap);
    return CImVec4{v4.x, v4.y, v4.z, v4.w};
}
CIMPLOT_API CImVec4 ImPlot_SampleColormap(float t, ImPlotColormap cmap) {
    auto v4 = ImPlot::SampleColormap(t, cmap);
    return CImVec4{v4.x, v4.y, v4.z, v4.w};
}
CIMPLOT_API void ImPlot_ColormapScale(const char* label, double scale_min, double scale_max, const ImVec2 size, const char* format, ImPlotColormapScaleFlags flags, ImPlotColormap cmap) {
    ImPlot::ColormapScale(label, scale_min, scale_max, size, format, flags, cmap);
}
CIMPLOT_API bool ImPlot_ColormapSlider(const char* label, float* t, ImVec4* out, const char* format, ImPlotColormap cmap) {
    return ImPlot::ColormapSlider(label, t, out, format, cmap);
}
CIMPLOT_API bool ImPlot_ColormapButton(const char* label, const ImVec2 size, ImPlotColormap cmap) {
    return ImPlot::ColormapButton(label, size, cmap);
}
CIMPLOT_API void ImPlot_BustColorCache(const char* plot_title_id) {
    ImPlot::BustColorCache(plot_title_id);
}

CIMPLOT_API ImPlotInputMap* ImPlot_GetInputMap() {  return &ImPlot::GetInputMap();}
CIMPLOT_API void ImPlot_MapInputDefault(ImPlotInputMap* dst) {
    ImPlot::MapInputDefault(dst);
}
CIMPLOT_API void ImPlot_MapInputReverse(ImPlotInputMap* dst) {
    ImPlot::MapInputReverse(dst);
}
CIMPLOT_API void ImPlot_ItemIcon_ImVec4(const ImVec4 col) {
    ImPlot::ItemIcon(col);
}
CIMPLOT_API void ImPlot_ItemIcon_ImU32(ImU32 col) {
    ImPlot::ItemIcon(col);
}
CIMPLOT_API void ImPlot_ColormapIcon(ImPlotColormap cmap) {
    ImPlot::ColormapIcon(cmap);
}
CIMPLOT_API ImDrawList* ImPlot_GetPlotDrawList() {
    return ImPlot::GetPlotDrawList();
}
CIMPLOT_API void ImPlot_PushPlotClipRect(float expand) {
    ImPlot::PushPlotClipRect(expand);
}
CIMPLOT_API void ImPlot_PopPlotClipRect() {
    ImPlot::PopPlotClipRect();
}
CIMPLOT_API bool ImPlot_ShowStyleSelector(const char* label) {
    return ImPlot::ShowStyleSelector(label);
}
CIMPLOT_API bool ImPlot_ShowColormapSelector(const char* label) {
    return ImPlot::ShowColormapSelector(label);
}
CIMPLOT_API bool ImPlot_ShowInputMapSelector(const char* label) {
    return ImPlot::ShowInputMapSelector(label);
}
CIMPLOT_API void ImPlot_ShowStyleEditor(ImPlotStyle* ref) {
    ImPlot::ShowStyleEditor(ref);
}
CIMPLOT_API void ImPlot_ShowUserGuide() {
    ImPlot::ShowUserGuide();
}
CIMPLOT_API void ImPlot_ShowMetricsWindow(bool* p_popen) {
    ImPlot::ShowMetricsWindow(p_popen);
}
// CIMPLOT_API void ImPlot_ShowDemoWindow(bool* p_open) {
//     ImPlot::ShowDemoWindow(p_open);
// }