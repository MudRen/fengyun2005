#include <ansi.h>
inherit ROOM;
void close_path();
string broketower();
void create()
{
	set("short", "断塔下");

	set("long", @LONG
从下面看过去，这原本据说是十三层的断塔显得异常高耸，越是走近，越觉得
似乎被压得透不过气来。巨大的山峦阴影正投在这里，黑乎乎的一片，什么也看不
见，也没什么声音，只有塔下一棵银杏树在山风中瑟瑟作响。	
LONG);
	set("long_night", @LONG
夜黑风高，四下黑乎乎一片，到了晚上就更不要指望看见什么。你隐约听到银
杏树下的草丛中似乎有人窃窃私语。
LONG);

	set("exits",([
		"northeast":__DIR__"shanlu3",
	]) );
	set("item_desc", ([
		"断塔" : (: broketower :), 	
		"broketower" : (: broketower :),
		"tower" : (: broketower :),
	]));
	set("outdoors", "bawang");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
}

void init (){
	add_action("do_listen", "listen");
}

string broketower(){
	object me;
	
	me = this_player();
	if(!query("exits/enter")){
		tell_object(me, "断塔下一小木门虚掩着。\n");
		add_action("do_push", "open");
	} else {
		tell_object(me, "四周一片漆黑，你什么也看不清。\n");
	}
	return "";
}

int do_push(string arg){
	object room, me;
	me = this_player();
	
	if (arg == "door" || arg == "木门") {
		if(query("exits/enter")){
	        return notify_fail("门已经打开了。\n");
		} 
		message_vision("$N轻轻在木门上一推，吱呀一声木门随手而开。\n", me);
		set("exits/enter", __DIR__"broketower");
		call_out("close_path", 4);
    	return 1;
    } 
    return 0;
}

int do_listen(string arg){
	object me, room;
	
	me = this_player();
	if(NATURE_D->is_day_time()){
		message_vision("四周一片寂静，偶尔听到风吹树叶的哗哗声。\n", me);
		return 1;
	}
	if(query("exits/enter")) {
		return 1;
	}
	tell_object(me,HIY "只听见塔顶有人缓缓说道：“你既然已经来了，还站在那里等什么？”\n"NOR);
	message("vision",me->name(me)+"突然驻足，似乎在侧耳倾听着什么。\n", environment(me),me);
	message_vision(HIW "\n旁边的银杏树下窜出一条黑影，打开了断塔下的一个小门，走了进去。\n"NOR, me);
	set("exits/enter", __DIR__"broketower");
    call_out("close_path", 5);
   	return 1;
}

void close_path(){
	if(query("exits/enter")) {
		message("vision", "小门“吱呀”一声，又关上了。\n",this_object());
		delete("exits/enter");
	}
}
