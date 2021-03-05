inherit ROOM;

void create()
{
        set("short", "莽林边缘");
        set("long", @LONG
沉香镇的东首是一片莽林，越走树林越密，树缝中洒下来的阳光也变得斑斑点
点。茅草渐厚，灌木丛生，吹来的风也越发的阴冷潮湿。远方密林的天空上有几只
盘旋的秃鹰，发出撕心裂肺的叫声，令人毛骨耸然。林边歪歪扭扭地挂着张告示：
		[33m『向东莽林，猛兽出没，闲人莫入』[32m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"groupw1",
  		"west" : AREA_CHENXIANG"cxe3",
	]));
        set("outdoors", "manglin");
	set("NONPC",1);
	set("coor/x",-410);
	set("coor/y",-100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
