//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "平原路");
	set("long", @LONG
大道自北向南，地势渐平。路面铺着小石子，一条条车痕向南方和北方伸展，
光脚走在上面，觉得颇为硌脚。道两旁的树木越来越少，骄阳似火，真想找个地方
休息一下。西面的支路是著名的风云道，蜿蜒数百里一直通向[33m沉香镇[32m。
LONG
	   );
	set("exits", 
	   ([ 
	     	"north" : __DIR__"woodsroad",
	     	"south" : __DIR__"southsearoad",
         	"west" : AREA_CHENXIANG"fydao3",
	    ]));
	set("outdoors", "baiyun");
	set("NONPC",1);
	set("coor/x",60);
	set("coor/y",-220);
	set("coor/z",10);
	setup();
}
