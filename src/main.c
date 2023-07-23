#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_UNDECORATED);

	InitWindow(250, 130, "Test Window");

	// General variables
	Vector2 mousePosition = { 0 };
	Vector2 windowPosition = { 500, 200 };
	Vector2 panOffset = mousePosition;
	bool dragWindow = false;

	SetWindowPosition(windowPosition.x, windowPosition.y);

	bool exitWindow = false;

	SetTargetFPS(60);

	float variableA = 0.0f;
	float variableB = -0.0f;
	float result = 0.0f;
	char operation[2];
	operation[0] = '+';
	operation[1] = '\0';

	bool variableAMode = false;
	bool variableBMode = false;
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!exitWindow && !WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !dragWindow)
		{
			if (CheckCollisionPointRec(mousePosition, (Rectangle){ 0, 0, (float)GetScreenWidth(), 20 }))
			{
				dragWindow = true;
				panOffset = mousePosition;
			}
		}

		if (dragWindow)
		{
			windowPosition.x += (mousePosition.x - panOffset.x);
			windowPosition.y += (mousePosition.y - panOffset.y);

			SetWindowPosition((int)windowPosition.x, (int)windowPosition.y);

			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) dragWindow = false;
		}


		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		exitWindow = GuiWindowBox((Rectangle){ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, "#198# CALCULATOR");

		if (GuiFloatBox((Rectangle){ 10, 40, 100, 20 }, NULL, &variableA, -1000000.0, 1000000.0, variableAMode)) variableAMode = !variableAMode;
		if (GuiFloatBox((Rectangle){ 140, 40, 100, 20 }, NULL, &variableB, -1000000.0, 1000000.0, variableBMode)) variableBMode = !variableBMode;
		
		if (GuiButton((Rectangle){ 10, 100, 50, 20 }, "+"))
		{
			result = variableA + variableB;
			operation[0] = '+';
		}
		if (GuiButton((Rectangle){ 70, 100, 50, 20 }, "-")) 
		{
			result = variableA - variableB;
			operation[0] = '-';
		}
		if (GuiButton((Rectangle){ 130, 100, 50, 20 }, "*")) 
		{
			result = variableA * variableB;
			operation[0] = '*';
		}
		if (GuiButton((Rectangle){ 190, 100, 50, 20 }, "/")) 
		{
			result = variableA / variableB;
			operation[0] = '/';
		}

		DrawText(operation, 123, 45, 10, DARKGRAY);
		
		GuiFloatBox((Rectangle){ 55, 70, 135, 20 }, "= ", &result, -2000000.0, 2000000.0, false);
		
		EndDrawing();
	}

	CloseWindow();
}