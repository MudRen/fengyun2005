inherit ROOM;
void create()
{
        set("short", "风云西城门");
        set("long", @LONG
西城门阁矮小而破旧，守城卫兵斜戴着红樱帽，搂着长枪在打瞌睡。也许因为
西城区所住皆贫困撩倒之徒，这里的治安和卫生都不是很好。狂风掠过之时，满地
垃圾随风飞舞，夜幕降临之后，惨号和狞笑声此起彼伏。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wcloud5",
]));
        set("objects", ([
        __DIR__"npc/wind_solider": 2, 
			]) );
        set("outdoors", "fengyun");
        set("coor/x",-60);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
}


