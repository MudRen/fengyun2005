
inherit ROOM;

void create()
{
        set("short", "正堂");
        set("long", @LONG
屋内光线充足，正对大门靠墙摆着一张紫檀木桌，上面摊放着一幅还没有完成
的字画，遒劲的笔力显示着作画人深厚的功力。进门两侧是几张紫檀木椅，墙上参
差有序地挂着一些名人字画。
LONG
        );
    set("exits", ([ 
  		"west" : __DIR__"bieyuan",
	]));
 
 	set("objects", ([
 		__DIR__"npc/kumeimaster" : 1,
 	]));  
    set("indoors", "huashan");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

