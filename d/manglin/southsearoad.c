//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "南海大道");
	set("long", @LONG
这是通往南海的一条必经之路，路面上的沙石越来越细，空气中弥漫着一股咸
味，越往南走，咸味越明显。远处隐隐传来波涛拍岸的声音。这条干线上商旅不绝，
大道的西边是“狐狸窝”，你随时可以看到三五成群的水手结伴而来，其目的地都
是西边的“狐狸窝”，时不时也有人从狐狸窝里出来，直奔对面的狐记当铺，然后
又一头扎回了狐狸窝里。
LONG
	   );
	set("exits", 
	   ([ 
	     "north" : __DIR__"plainroad",
	     "south" : __DIR__"southsearoad1",
	     "west"  : __DIR__"foxhotel",
	     "east"  : __DIR__"foxdangpu",
	    ]));
	set("objects", 
	   ([ 
         AREA_BAIYUN"npc/sailor" : 3,
	    ]));

	set("outdoors", "baiyun");
	set("coor/x",60);
	set("coor/y",-230);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
