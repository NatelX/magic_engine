# Magic Engine
Magic Engine is an open source toolset for creating online video games.

MagicEditor is written in wxWidgets library and will be everthing you need to create your own online game.

# Milestones:
 - add support for creating vulkan context in wxWidgets (clear window example)
 - add support for creating directx 12 context in wxWidgets (clear window example)
 
#Compilation guide:
1. Insert wxWidgets include files into: MagicEditor\vendor\wxWidgets\include
2. Insert wxWidgets libraries files into: MagicEditor\vendor\wxWidgets\lib\vc_x64_lib
3. Insert vulkan include files into: MagicEngine\vendor\vulkan\Include
4. Insert vulkan libraries files into: MagicEngine\vendor\vulkan\lib

Note:
You can change wxWidgets and vulkan directory path in premake file! 
