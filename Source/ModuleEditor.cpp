#include "Application.h"
#include "JsonParser.h"
#include "ModuleEditor.h"
#include "IMGUI\imgui.h"
#include "IMGUI\imgui_impl_sdl_gl3.h"
#include "../Libraries/OpenGL/include/GL/glew.h"
#pragma comment (lib, "opengl32.lib") 
#include "ModuleWindow.h"


ModuleEditor::ModuleEditor()
{
}

ModuleEditor::~ModuleEditor()
{
}

bool ModuleEditor::Init()
{
	ImGui_ImplSdlGL3_Init(App->window->window);
	return true;
}

update_status ModuleEditor::PreUpdate(float dt)
{
	ImGui_ImplSdlGL3_NewFrame(App->window->window);

	return UPDATE_CONTINUE;
}

update_status ModuleEditor::Update(float dt)
{
	DrawConsole();
	if(fps_log.size() != 0)
		DrawFps();
	return UPDATE_CONTINUE;
}

update_status ModuleEditor::PostUpdate(float dt)
{
	//ImGui::ShowTestWindow();

	return UPDATE_CONTINUE;
}

void ModuleEditor::DrawConsole()
{
	ImGui::SetNextWindowSize(ImVec2(100, 100), ImGuiSetCond_FirstUseEver);
	ImGui::Begin("Console", NULL, 0);
	ImGui::TextUnformatted(Buf.begin());
	ImGui::End();
}

void ModuleEditor::DrawFps()
{
	ImGui::SetNextWindowSize(ImVec2(300, 300), ImGuiSetCond_FirstUseEver);
	ImGui::Begin("Histogram", NULL, 0);
	ImGui::PlotHistogram("##framerate", &fps_log[0], fps_log.size(), 0, "Frames", 0.0f, 100.0f, ImVec2(310, 100));
	ImGui::End();
}

void ModuleEditor::AddFps(float fps)
{
	fps_log.push_back(fps);
}

void ModuleEditor::AddLog(const char * fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	Buf.appendv(fmt, args);
	Buf.appendv("\n", nullptr);
	va_end(args);
}


bool ModuleEditor::CleanUp()
{
	ImGui_ImplSdlGL3_Shutdown();
	return true;
}


void ModuleEditor::InputHandler(SDL_Event* event)
{
	ImGui_ImplSdlGL3_ProcessEvent(event);
}
