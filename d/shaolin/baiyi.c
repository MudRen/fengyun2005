// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "白衣殿");
        set("long", @LONG
殿内壁画大多是少林拳谱壁画，所以又称拳谱殿。殿内正中供奉白衣菩萨象，
北壁绘有拳法壁画，南壁是器械功夫，还有十三棍僧救唐王的故事更是名扬四海。
这些壁画对于初学少林武功的人来说是相当有帮助的。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"qianfe",
]));
        set("objects", ([
                __DIR__"npc/monk_float" : 2,
       ]) );
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
