// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","梦仙龛");
  set("long",@LONG
沿朝阳向东北去，便到梦仙龛，一路白云飘浮，山风阵阵，夹道树木俱是百年
松柏，郁郁苍苍，远处眺望，山烟弥漫，伴随阵阵凉风，不由让人飘飘欲仙，相传
这里是唐皇游山到此小憩，梦见碧霞元君的所在，山林中立有小小一神龛，十分精
致，想来也花费无数能工巧匠之力。远处树木越来越密，再往东便是老云寨了。
LONG
  );
  set("exits",([
	"east" : AREA_OLDPINE"npath1",
	"westdown" : __DIR__"chaoyang",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",100);
	setup();
  	replace_program(ROOM);
}

 
/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

