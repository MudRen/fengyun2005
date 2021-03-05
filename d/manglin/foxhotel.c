//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "狐狸窝");
	set("long", @LONG
终年飘浮在海上的人们，提起“狐狸窝”这三个字，就会露出神秘而愉快的微笑，
心里也会觉得火辣辣的，就好像刚喝了杯烈酒。只要男人们能想得到的事，在狐狸窝
里都可以找得到。用木板搭成的屋子已很破旧，但是没人在乎。温暖潮湿的海风从窗
外的海上吹过来，带着种令人愉快的咸味。屋子里烟雾腾腾，女人头上的刨花油香味
和烧鱼的味道混合在—起，足以激起男人们的各种欲望。
LONG
	   );
	set("exits", 
	   ([ 
	     "east"  : __DIR__"southsearoad"
	    ]));
       set("objects", 
          ([ 
        AREA_BAIYUN"npc/niuroutang" : 1,
            ]));
    set("indoors", "baiyun");
	set("coor/x",50);
	set("coor/y",-230);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
