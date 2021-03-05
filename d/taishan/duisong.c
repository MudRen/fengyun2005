// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","对松亭");
  set("long",@LONG
此处南天门之下，双峰对峙，又名对松山或万松山，浓密的松树层层叠叠于绝
壁之上，松涛随山风呼啸，声如巨浪拍岸，苍松衬浮云而隐现，势若蟠龙飞舞，令
人身居松谷，心荡神驰，相传乾隆皇帝曾手书“岱宗最佳处，对松真奇绝”。
LONG
  );
  set("exits",([
	"down" : __DIR__"chaoyang",
	"up" : __DIR__"shiba",
               ]));
        set("objects", ([
        __DIR__"npc/zhu" : 1,
	__DIR__"npc/zyc" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",100);
	setup();
  	replace_program(ROOM);
}
