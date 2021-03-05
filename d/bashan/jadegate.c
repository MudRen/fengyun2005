// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "绿松石门");
    set("long", @LONG
一条蜿蜒的小路依稀，曲曲折折地向北面的深谷中延去，面前屹立的则是一扇
巨大的石门，两丈多高，三丈多宽。细看之下，这如此巨大厚重的大门竟是严密无
缝的一整块绿松石刻，看起来绝非人力所能够推动。石门一侧立着一块青玉碑，碑
上雕着两行诗文。
LONG
    );
    set("exits",([
	"east" : __DIR__"maze1/exit",
	"northup" : "/d/potboil/41",
      ]) );
    set("objects", ([
	__DIR__"mazenpc/gatekeeper" :1,
	__DIR__"mazenpc/gatekeeper2" :1,
      ]) );
    set("item_desc", ([
	"青玉碑": "青玉碑文上雕着两行诗文：\n\n"CYN"　　　　仰　　凉\n　　　　对　　生\n　　　　长　　墨\n　　　　空　　岭\n　　　　叶　　心\n　　　　舒　　无\n　　　　轻　　定\n\n"NOR"碑下有两个小孔，似乎可以插(insert)进什么东西。\n",
	"碑": "青玉碑文上雕着两行诗文：\n\n"CYN"　　　　仰　　凉\n　　　　对　　生\n　　　　长　　墨\n　　　　空　　岭\n　　　　叶　　心\n　　　　舒　　无\n　　　　轻　　定\n\n"NOR"碑下有两个小孔，似乎可以插(insert)进什么东西。\n",
      ]) );

    set("outdoors", "bashan");

    set("coor/x",-20);
    set("coor/y",0);
    set("coor/z",0);
    setup();
}

void init()
{
    add_action("do_insert","insert");
    add_action("do_i","go");
}

int do_i(string arg)
{
    if (arg == "west")
	tell_object(this_player(),"这个方向的出路被绿松石门阻住了。\n");
    return 0;
}

int do_insert(string arg)
{
    object env = this_object(),ob,me = this_player();
    if (!arg)
	return notify_fail("你要插什么？\n");
    if (!ob=present(arg,me))
	return notify_fail("你要插什么？\n");
    if ( crc32(crypt("a"+ob->query_weight()+"n","n"+crc32(ob->query_weight()+"")+"ie")) != 1026565555)
	return notify_fail("这样东西无法被插入。\n");
    if (crc32(crypt(ob->name(),crc32(ob->name()))) != -2090929369)
	return notify_fail("这样东西无法被插入。\n");
    if (query("already_closed"))
	return notify_fail("青玉石碑上的小孔中已经插有东西了。\n");
    // snicker...猜猜看，插什么？
    message_vision(WHT"$N将一"+ob->query("unit")+ob->name()+WHT"插进了青玉石碑上的小孔中。\n"NOR,me);
    add("ins",1);
    set("item_desc", ([
	"青玉碑": "青玉碑文上雕着两行诗文：\n\n"CYN"　　　　仰　　凉\n　　　　对　　生\n　　　　长　　墨\n　　　　空　　岭\n　　　　叶　　心\n　　　　舒　　无\n　　　　轻　　定\n\n"NOR"碑下有一个小孔，似乎可以插(insert)进什么东西。\n",
	"碑": "青玉碑文上雕着两行诗文：\n\n"CYN"　　　　仰　　凉\n　　　　对　　生\n　　　　长　　墨\n　　　　空　　岭\n　　　　叶　　心\n　　　　舒　　无\n　　　　轻　　定\n\n"NOR"碑下有一个小孔，似乎可以插(insert)进什么东西。\n",
      ]) );
    if (query("ins") == 2)
    {
	set("already_closed",1);
	message_vision(HIG"只听一阵雷鸣声响，绿松石门缓缓的滑向一边．．．\n"NOR,me);
	set("exits/west", __DIR__"restroom");
	set("item_desc", ([
	    "青玉碑": "青玉碑文上雕着两行诗文：\n\n"CYN"　　　　仰　　凉\n　　　　对　　生\n　　　　长　　墨\n　　　　空　　岭\n　　　　叶　　心\n　　　　舒　　无\n　　　　轻　　定\n"NOR,
	    "碑": "青玉碑文上雕着两行诗文：\n\n"CYN"　　　　仰　　凉\n　　　　对　　生\n　　　　长　　墨\n　　　　空　　岭\n　　　　叶　　心\n　　　　舒　　无\n　　　　轻　　定\n"NOR,
	  ]) );
    }
    destruct(ob);
    return 1;
}


int valid_leave(object me, string dir)
{
    if( dir == "west")
    {
	add("ins",-1);
	if (query("ins") < 0)
	{
	    delete("exits/west");
	    message_vision(CYN"$N正要举步，就听得一阵沉闷的鸣声传来，绿松石门轰的一声合了上去。\n"NOR,me);
	    return notify_fail("这个方向已经没有出路了。\n");
	}
	return 1;
    }
    return 1;
}




/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

