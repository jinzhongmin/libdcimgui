#include "implot.h"
#include "stdbool.h"
#include <cstddef>

#pragma once

#ifndef CIMPLOT_API
#define CIMPLOT_API
#endif // #ifndef CIMGUI_API

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CImVec4{
    float x, y, z, w;
}CImVec4;
typedef struct CImPlotPoint{
    double x, y;
}CImPlotPoint;

typedef  struct CImVec2{
    float x, y;
}CImVec2 ;

typedef struct CImPlotRange{
    double Min, Max;
}CImPlotRange;
typedef struct CImPlotRect{
    CImPlotRange X, Y;
} CImPlotRect;

CIMPLOT_API ImPlotContext *ImPlot_CreateContext();
CIMPLOT_API void ImPlot_DestroyContext(ImPlotContext *ctx);
CIMPLOT_API ImPlotContext *ImPlot_GetCurrentContext();
CIMPLOT_API void ImPlot_SetCurrentContext(ImPlotContext *ctx);
CIMPLOT_API void ImPlot_SetImGuiContext(ImGuiContext *ctx);

CIMPLOT_API bool ImPlot_BeginPlot(const char *title_id, const ImVec2 size,
                                  ImPlotFlags flags);
CIMPLOT_API void ImPlot_EndPlot();

CIMPLOT_API bool ImPlot_BeginSubplots(const char *title_id, int rows, int cols,
                                      const ImVec2 size,
                                      ImPlotSubplotFlags flags = 0,
                                      float *row_ratios = nullptr,
                                      float *col_ratios = nullptr);
CIMPLOT_API void ImPlot_EndSubplots();
CIMPLOT_API void ImPlot_SetupAxis(ImAxis axis, const char *label = 0, ImPlotAxisFlags flags = 0);
CIMPLOT_API void ImPlot_SetupAxisLimits(ImAxis axis, double v_min, double v_max, ImPlotCond cond = ImPlotCond_Once);
CIMPLOT_API void ImPlot_SetupAxisLinks(ImAxis axis, double *link_min, double *link_max);
CIMPLOT_API void ImPlot_SetupAxisFormat(ImAxis axis, const char *fmt);
CIMPLOT_API void ImPlot_SetupAxisFormatCallback(ImAxis axis, ImPlotFormatter formatter, void *data);
CIMPLOT_API void ImPlot_SetupAxisTicks(ImAxis axis, const double *values, int n_ticks, const char *const* labels = NULL, bool keep_default=false);
CIMPLOT_API void ImPlot_SetupAxisTicksRange(ImAxis axis, double v_min, double v_max, int n_ticks, const char *const* labels = NULL, bool keep_default=false);
CIMPLOT_API void ImPlot_SetupAxisScale(ImAxis axis, ImPlotScale scale);
CIMPLOT_API void ImPlot_SetupAxisScaleTransform(ImAxis axis, ImPlotTransform forward, ImPlotTransform inverse, void* data/*=nullptr*/);
CIMPLOT_API void ImPlot_SetupAxisLimitsConstraints(ImAxis axis, double v_min, double v_max);
CIMPLOT_API void ImPlot_SetupAxisZoomConstraints(ImAxis axis, double v_min, double v_max);
CIMPLOT_API void ImPlot_SetupAxes(const char* x_label, const char* y_label, ImPlotAxisFlags x_flags /*=0*/, ImPlotAxisFlags y_flags /*=0*/);
CIMPLOT_API void ImPlot_SetupAxesLimits(double x_min, double x_max, double y_min, double y_max, ImPlotCond cond /*= ImPlotCond_Once*/);
CIMPLOT_API void ImPlot_SetupLegend(ImPlotLocation location, ImPlotLegendFlags flags/*=0*/);
CIMPLOT_API void ImPlot_SetupMouseText(ImPlotLocation location, ImPlotMouseTextFlags flags/*=0*/);
CIMPLOT_API void ImPlot_SetupFinish();
CIMPLOT_API void ImPlot_SetNextAxisLimits(ImAxis axis, double v_min, double v_max, ImPlotCond cond/*= ImPlotCond_Once*/);
CIMPLOT_API void ImPlot_SetNextAxisLinks(ImAxis axis, double *link_min, double *link_max);
CIMPLOT_API void ImPlot_SetNextAxisToFit(ImAxis axis);
CIMPLOT_API void ImPlot_SetNextAxesLimits(double x_min, double x_max, double y_min, double y_max, ImPlotCond cond /*= ImPlotCond_Once*/);
CIMPLOT_API void ImPlot_SetNextAxesToFit();

CIMPLOT_API void ImPlot_PlotLine(ImGuiDataType dtype, const char *label_id, const void *values, int count, double xscale /*= 1*/, double xstart /*= 0*/, ImPlotLineFlags flags /*= 0*/, int offset /*= 0*/); 
CIMPLOT_API void ImPlot_PlotLine2D(ImGuiDataType dtype, const char *label_id, const void *xs, const void *ys, int count, ImPlotLineFlags flags /*= 0*/, int offset /*= 0*/);
CIMPLOT_API void ImPlot_PlotLineG(const char* label_id, ImPlotGetter getter, void* data, int count, ImPlotLineFlags flags /*=0*/);
CIMPLOT_API void ImPlot_PlotScatter(ImGuiDataType dtype, const char* label_id, const void* values, int count, double xscale/*=1*/, double xstart/*=0*/, ImPlotScatterFlags flags/*=0*/, int offset/*=0*/);
CIMPLOT_API void ImPlot_PlotScatter2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, ImPlotScatterFlags flags /*=0*/, int offset/*=0*/);
CIMPLOT_API void ImPlot_PlotScatterG(const char* label_id, ImPlotGetter getter, void* data, int count, ImPlotScatterFlags flags/* = 0*/);
CIMPLOT_API void ImPlot_PlotStairs(ImGuiDataType dtype, const char* label_id, const void* values, int count, double xscale = 1, double xstart = 0, ImPlotStairsFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotStairs2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, ImPlotStairsFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotStairsG(const char* label_id, ImPlotGetter getter, void* data, int count, ImPlotStairsFlags flags = 0);
CIMPLOT_API void ImPlot_PlotShaded(ImGuiDataType dtype, const char* label_id, const void* values, int count, double xscale = 1, double xstart = 0, double yref = 0, ImPlotShadedFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotShaded2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, double yref = 0, ImPlotShadedFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotShaded2Y(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys1, const void* ys2, int count, ImPlotShadedFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotShadedG(const char* label_id, ImPlotGetter getter1, void* data1, ImPlotGetter getter2, void* data2, int count, ImPlotShadedFlags flags = 0);
CIMPLOT_API void ImPlot_PlotBars(ImGuiDataType dtype, const char* label_id, const void* values, int count, double bar_size = 0.67, double shift = 0, ImPlotBarsFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotBars2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, double bar_size, ImPlotBarsFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotBarsG(const char* label_id, ImPlotGetter getter, void* data, int count, double bar_size, ImPlotBarsFlags flags = 0);

CIMPLOT_API void ImPlot_PlotBarGroups(ImGuiDataType dtype, const char** const label_ids, const void* values, int item_count, int group_count, double group_size = 0.67, double shift = 0, ImPlotBarGroupsFlags flags = 0);
CIMPLOT_API void ImPlot_PlotErrorBars(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, const void* err, int count, ImPlotErrorBarsFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotErrorBarsNeg(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, const void* neg, const void* pos, int count, ImPlotErrorBarsFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotStems(ImGuiDataType dtype, const char* label_id, const void* values, int count, double ref = 0, double scale = 1, double start = 0, ImPlotStemsFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotStems2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, double ref = 0, ImPlotStemsFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotInfLines(ImGuiDataType dtype, const char* label_id, const void* values, int count, ImPlotInfLinesFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotPieChart_Fmt(ImGuiDataType dtype, const char* const* label_ids, const void* values, int count, double x, double y, double radius, ImPlotFormatter fmt, void* fmt_data = nullptr, double angle0 = 90, ImPlotPieChartFlags flags = 0);
CIMPLOT_API void ImPlot_PlotPieChart(ImGuiDataType dtype, const char* const* label_ids, const void* values, int count, double x, double y, double radius, const char* label_fmt = "%.1f", double angle0 = 90, ImPlotPieChartFlags flags = 0);


CIMPLOT_API void ImPlot_PlotHeatmap(ImGuiDataType dtype, const char* label_id, const void* values, int rows, int cols, double scale_min = 0, double scale_max = 0, const char* label_fmt = "%.1f", const ImPlotPoint bounds_min = ImPlotPoint(0,0), const ImPlotPoint bounds_max = ImPlotPoint(1,1), ImPlotHeatmapFlags flags = 0);
CIMPLOT_API double ImPlot_PlotHistogram(ImGuiDataType dtype, const char* label_id, const void* values, int count, int bins = ImPlotBin_Sturges, double bar_scale = 1.0, ImPlotRange range = ImPlotRange(), ImPlotHistogramFlags flags = 0);
CIMPLOT_API double ImPlot_PlotHistogram2D(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, int x_bins = ImPlotBin_Sturges, int y_bins = ImPlotBin_Sturges, ImPlotRect range = ImPlotRect(), ImPlotHistogramFlags flags = 0);
CIMPLOT_API void ImPlot_PlotDigital(ImGuiDataType dtype, const char* label_id, const void* xs, const void* ys, int count, ImPlotDigitalFlags flags = 0, int offset = 0);
CIMPLOT_API void ImPlot_PlotDigitalG(const char* label_id, ImPlotGetter getter, void* data, int count, ImPlotDigitalFlags flags = 0);
// #ifdef IMGUI_HAS_TEXTURES
CIMPLOT_API void ImPlot_PlotImage(const char* label_id, ImTextureRef tex_ref, const ImPlotPoint bounds_min, const ImPlotPoint bounds_max, const ImVec2 uv0 = ImVec2(0,0),const ImVec2 uv1 = ImVec2(1, 1), const ImVec4 tint_col = ImVec4(1,1,1,1), ImPlotImageFlags flags = 0);
// #else
// CIMPLOT_API void ImPlot_PlotImage(const char* label_id, ImTextureID tex_ref, const ImPlotPoint bounds_min, const ImPlotPoint bounds_max, const ImVec2 uv0 = ImVec2(0,0), const ImVec4 tint_col = ImVec4(1,1,1,1), ImPlotImageFlags flags = 0);
// #endif
CIMPLOT_API void ImPlot_PlotText(const char* text, double x, double y, const ImVec2 pix_offset = ImVec2(0,0), ImPlotTextFlags flags = 0);
CIMPLOT_API void ImPlot_PlotDummy(const char* label_id, ImPlotDummyFlags flags = 0);

CIMPLOT_API bool ImPlot_DragPoint(int id, double* x, double* y, const ImVec4 col, float size = 4, ImPlotDragToolFlags flags = 0, bool* out_clicked = nullptr, bool* out_hovered = nullptr, bool* held = nullptr);
CIMPLOT_API bool ImPlot_DragLineX(int id, double* x, const ImVec4 col, float thickness = 1, ImPlotDragToolFlags flags = 0, bool* out_clicked = nullptr, bool* out_hovered = nullptr, bool* held = nullptr);
CIMPLOT_API bool ImPlot_DragLineY(int id, double* y, const ImVec4 col, float thickness = 1, ImPlotDragToolFlags flags = 0, bool* out_clicked = nullptr, bool* out_hovered = nullptr, bool* held = nullptr);
CIMPLOT_API bool ImPlot_DragRect(int id, double* x1, double* y1, double* x2, double* y2, const ImVec4 col, ImPlotDragToolFlags flags = 0, bool* out_clicked = nullptr, bool* out_hovered = nullptr, bool* held = nullptr);

CIMPLOT_API void ImPlot_Annotation_Round(double x, double y, const ImVec4 col, const ImVec2 pix_offset = ImVec2(0,0), bool clamp = false, bool round = false);
CIMPLOT_API void ImPlot_Annotation(double x, double y, const ImVec4 col, const ImVec2 pix_offset = ImVec2(0,0), bool clamp = false, const char* text="");
CIMPLOT_API void ImPlot_Annotation_Fmt(double x, double y, const ImVec4 col, const ImVec2 pix_offset = ImVec2(0,0), bool clamp = false, const char* fmt = "", ...);
CIMPLOT_API void ImPlot_TagX(double x, const ImVec4 col, bool round = false);
CIMPLOT_API void ImPlot_TagX_Fmt(double x, const ImVec4 col, const char* fmt = "", ...);
CIMPLOT_API void ImPlot_TagY(double y, const ImVec4 col, bool round = false);
CIMPLOT_API void ImPlot_TagY_Fmt(double y, const ImVec4 col, const char* fmt = "", ...);

CIMPLOT_API void ImPlot_SetAxis(ImAxis axis);
CIMPLOT_API void ImPlot_SetAxes(ImAxis x_axis, ImAxis y_axis);
CIMPLOT_API CImPlotPoint ImPlot_PixelsToPlot(const ImVec2 pix, ImAxis x_axis = IMPLOT_AUTO, ImAxis y_axis = IMPLOT_AUTO);
CIMPLOT_API CImPlotPoint ImPlot_PixelsToPlotXY(float x, float y, ImAxis x_axis = IMPLOT_AUTO, ImAxis y_axis = IMPLOT_AUTO);
CIMPLOT_API CImVec2 ImPlot_PlotToPixels(const ImPlotPoint plt, ImAxis x_axis = IMPLOT_AUTO, ImAxis y_axis = IMPLOT_AUTO);
CIMPLOT_API CImVec2 ImPlot_PlotToPixelsXY(double x, double y, ImAxis x_axis = IMPLOT_AUTO, ImAxis y_axis = IMPLOT_AUTO);
CIMPLOT_API CImVec2 ImPlot_GetPlotPos();
CIMPLOT_API CImVec2 ImPlot_GetPlotSize();
CIMPLOT_API CImPlotPoint ImPlot_GetPlotMousePos(ImAxis x_axis = IMPLOT_AUTO, ImAxis y_axis = IMPLOT_AUTO);
CIMPLOT_API CImPlotRect ImPlot_GetPlotLimits(ImAxis x_axis = IMPLOT_AUTO, ImAxis y_axis = IMPLOT_AUTO);
CIMPLOT_API bool ImPlot_IsPlotHovered();
CIMPLOT_API bool ImPlot_IsAxisHovered(ImAxis axis);
CIMPLOT_API bool ImPlot_IsSubplotsHovered();
CIMPLOT_API bool ImPlot_IsPlotSelected();
CIMPLOT_API CImPlotRect ImPlot_GetPlotSelection(ImAxis x_axis = IMPLOT_AUTO, ImAxis y_axis = IMPLOT_AUTO);
CIMPLOT_API void ImPlot_CancelPlotSelection();
CIMPLOT_API void ImPlot_HideNextItem(bool hidden = true, ImPlotCond cond = ImPlotCond_Once);
CIMPLOT_API bool ImPlot_BeginAlignedPlots(const char* group_id, bool vertical = true);
CIMPLOT_API void ImPlot_EndAlignedPlots();

CIMPLOT_API bool ImPlot_BeginLegendPopup(const char* label_id, ImGuiMouseButton mouse_button = 1);
CIMPLOT_API void ImPlot_EndLegendPopup();
CIMPLOT_API bool ImPlot_IsLegendEntryHovered(const char* label_id);
CIMPLOT_API bool ImPlot_BeginDragDropTargetPlot();
CIMPLOT_API bool ImPlot_BeginDragDropTargetAxis(ImAxis axis);
CIMPLOT_API bool ImPlot_BeginDragDropTargetLegend();
CIMPLOT_API void ImPlot_EndDragDropTarget();
CIMPLOT_API bool ImPlot_BeginDragDropSourcePlot(ImGuiDragDropFlags flags = 0);
CIMPLOT_API bool ImPlot_BeginDragDropSourceAxis(ImAxis axis, ImGuiDragDropFlags flags = 0);
CIMPLOT_API bool ImPlot_BeginDragDropSourceItem(const char* label_id, ImGuiDragDropFlags flags = 0);
CIMPLOT_API void ImPlot_EndDragDropSource();

CIMPLOT_API ImPlotStyle* ImPlot_GetStyle();
CIMPLOT_API void ImPlot_StyleColorsAuto(ImPlotStyle* dst = nullptr);
CIMPLOT_API void ImPlot_StyleColorsClassic(ImPlotStyle* dst = nullptr);
CIMPLOT_API void ImPlot_StyleColorsDark(ImPlotStyle* dst = nullptr);
CIMPLOT_API void ImPlot_StyleColorsLight(ImPlotStyle* dst = nullptr);
CIMPLOT_API void ImPlot_PushStyleColor_ImU32(ImPlotCol idx, ImU32 col);
CIMPLOT_API void ImPlot_PushStyleColor_ImVec4(ImPlotCol idx, const ImVec4 col);
CIMPLOT_API void ImPlot_PopStyleColor(int count = 1);
CIMPLOT_API void ImPlot_PushStyleVar_Float(ImPlotStyleVar idx, float val);
CIMPLOT_API void ImPlot_PushStyleVar_Int(ImPlotStyleVar idx, int val);
CIMPLOT_API void ImPlot_PushStyleVar_ImVec2(ImPlotStyleVar idx, const ImVec2 val);
CIMPLOT_API void ImPlot_PopStyleVar(int count = 1);
CIMPLOT_API void ImPlot_SetNextLineStyle(const ImVec4 col = IMPLOT_AUTO_COL, float weight = IMPLOT_AUTO);
CIMPLOT_API void ImPlot_SetNextFillStyle(const ImVec4 col = IMPLOT_AUTO_COL, float alpha_mod = IMPLOT_AUTO);
CIMPLOT_API void ImPlot_SetNextMarkerStyle(ImPlotMarker marker = IMPLOT_AUTO, float size = IMPLOT_AUTO, const ImVec4 fill = IMPLOT_AUTO_COL, float weight = IMPLOT_AUTO, const ImVec4 outline = IMPLOT_AUTO_COL);
CIMPLOT_API void ImPlot_SetNextErrorBarStyle(const ImVec4 col = IMPLOT_AUTO_COL, float size = IMPLOT_AUTO, float weight = IMPLOT_AUTO);
CIMPLOT_API CImVec4 ImPlot_GetLastItemColor();
CIMPLOT_API const char* ImPlot_GetStyleColorName(ImPlotCol idx);
CIMPLOT_API const char* ImPlot_GetMarkerName(ImPlotMarker idx);

CIMPLOT_API ImPlotColormap ImPlot_AddColormap_ImVec4(const char* name, const ImVec4* cols, int size, bool qual = true);
CIMPLOT_API ImPlotColormap ImPlot_AddColormap_ImU32(const char* name, const ImU32* cols, int size, bool qual = true);
CIMPLOT_API int ImPlot_GetColormapCount();
CIMPLOT_API const char* ImPlot_GetColormapName(ImPlotColormap cmap);
CIMPLOT_API ImPlotColormap ImPlot_GetColormapIndex(const char* name);
CIMPLOT_API void ImPlot_PushColormap_Index(ImPlotColormap cmap);
CIMPLOT_API void ImPlot_PushColormap_Name(const char* name);
CIMPLOT_API void ImPlot_PopColormap(int count = 1);
CIMPLOT_API CImVec4 ImPlot_NextColormapColor();
CIMPLOT_API int ImPlot_GetColormapSize(ImPlotColormap cmap = IMPLOT_AUTO);
CIMPLOT_API CImVec4 ImPlot_GetColormapColor(int idx, ImPlotColormap cmap = IMPLOT_AUTO);
CIMPLOT_API CImVec4 ImPlot_SampleColormap(float t, ImPlotColormap cmap = IMPLOT_AUTO);
CIMPLOT_API void ImPlot_ColormapScale(const char* label, double scale_min, double scale_max, const ImVec2 size = ImVec2(0,0), const char* format = "%g", ImPlotColormapScaleFlags flags = 0, ImPlotColormap cmap = IMPLOT_AUTO);
CIMPLOT_API bool ImPlot_ColormapSlider(const char* label, float* t, ImVec4* out = nullptr, const char* format = "", ImPlotColormap cmap = IMPLOT_AUTO);
CIMPLOT_API bool ImPlot_ColormapButton(const char* label, const ImVec2 size = ImVec2(0,0), ImPlotColormap cmap = IMPLOT_AUTO);
CIMPLOT_API void ImPlot_BustColorCache(const char* plot_title_id = nullptr);

CIMPLOT_API ImPlotInputMap* ImPlot_GetInputMap();
CIMPLOT_API void ImPlot_MapInputDefault(ImPlotInputMap* dst = NULL);
CIMPLOT_API void ImPlot_MapInputReverse(ImPlotInputMap* dst = NULL);
CIMPLOT_API void ImPlot_ItemIcon_ImVec4(const ImVec4 col);
CIMPLOT_API void ImPlot_ItemIcon_ImU32(ImU32 col);
CIMPLOT_API void ImPlot_ColormapIcon(ImPlotColormap cmap);
CIMPLOT_API ImDrawList* ImPlot_GetPlotDrawList();
CIMPLOT_API void ImPlot_PushPlotClipRect(float expand = 0);
CIMPLOT_API void ImPlot_PopPlotClipRect();
CIMPLOT_API bool ImPlot_ShowStyleSelector(const char* label);
CIMPLOT_API bool ImPlot_ShowColormapSelector(const char* label);
CIMPLOT_API bool ImPlot_ShowInputMapSelector(const char* label);
CIMPLOT_API void ImPlot_ShowStyleEditor(ImPlotStyle* ref = NULL);
CIMPLOT_API void ImPlot_ShowUserGuide();
CIMPLOT_API void ImPlot_ShowMetricsWindow(bool* p_popen = NULL);
// CIMPLOT_API void ImPlot_ShowDemoWindow(bool* p_open = NULL);


#ifdef __cplusplus
}
#endif