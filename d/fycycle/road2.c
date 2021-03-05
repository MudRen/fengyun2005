#include <ansi.h>
inherit ROOM;
string jinqi();
void remove_flag();
void create()
{
        set("short", "茶亭南");
        set("long", @LONG
小路到此一弯。路的旁边是风云城的护城河，河的另外一边就是高大的风云城
城墙了。河堤上长满了绿草。微风拂来一股泥土的气息。北边是一座茶亭，一个老
人和一个小姑娘在忙着招呼客人，看起来生意不错。路的一旁围了一大群人，里面
摆了个场子，地下插了一面[33m锦旗[32m。
LONG
        );
    	set("exits", ([ /* sizeof() == 4 */
  		"north":__DIR__"tea_ting",
  		"northeast" : __DIR__"road3",
		"southwest" : __DIR__"road1",
	]));
	set("objects", ([
	    __DIR__"npc/badkid" : 1,
	    __DIR__"npc/laotou" : 1,
	    __DIR__"npc/thinmonk":1,
	    __DIR__"npc/qiuranke":1,
	    __DIR__"npc/hongfunv":1,
	]) );
    	set("item_desc", ([
		"jinqi" : (: jinqi :),
		"锦旗" : (: jinqi :),
		"flag" : (: jinqi :), 
    	]) );
	set("have_flag", 1);
        set("outdoors", "fengyun");
	set("coor/x",-200);
	set("coor/y",200);
	set("coor/z",0);

        setup();

}

string jinqi(){
	object me;
	me = this_player();
	if(!query("have_flag")){
		tell_object(me, "没有旗子了。\n");
		return "";
	}
	tell_object(me, HIY"                      比 武 招 亲\n"NOR);
    	tell_object(me, "            易得无价宝　     　　难求有情郎\n");
	tell_object(me, "\n凡年在三十岁以下，尚未娶亲，能胜得小女一拳一脚的，在下即将小女许配于\n");
	tell_object(me, "他。风云城乃卧虎藏龙之地，高人侠士必多，不为富贵荣华，但求英雄豪侠。\n");        
	tell_object(me, "如有意者，不妨一摘(ｚｈａｉ）地上所插锦旗！\n");
	return "";
}

void init(){
	add_action("do_zhai", "zhai");
}

int do_zhai(string arg){
	object me, qiu, hong, qi;
	me = this_player();
	if(!arg || (arg != "flag" && arg != "jinqi" && arg != "锦旗")) {
		return 0;
	}
	if (!query("have_flag")){
		tell_object(me,"已经被摘完了。\n");
		return 1;
	}
		
	message_vision("$N伸手试着去摘旗。\n", me);
	qiu = present("qiuran han", this_object());
	hong = present("redcloth girl", this_object());
	if(objectp(qiu) && objectp(hong)){
		qiu->zhaoqin(me);
	} else {
		message_vision("$N摘下一面小锦旗放入怀中。\n", me);
		remove_flag();
		qi = new(__DIR__"obj/qi");
		qi->move(me);
	}
	return 1;
}

void remove_flag(){
	set("have_flag", 0);
	set("long", @LONG
小路到此一弯。路的旁边是风云城的护城河，河的另外一边就是高大的风云城
城墙了。河堤上长满了绿草。微风拂来一股泥土的气息。北边是一座茶亭，一个老
人和一个小姑娘在忙着招呼客人，看起来生意不错。
LONG);
}

void reset(){
	::reset();
    set("long", @LONG
小路到此一弯。路的旁边是风云城的护城河，河的另外一边就是高大的风云城
城墙了。河堤上长满了绿草。微风拂来一股泥土的气息。北边是一座茶亭，一个老
人和一个小姑娘在忙着招呼客人，看起来生意不错。路的一旁围了一大群人，里面
摆了个场子，地下插了一面[33m锦旗[32m。
LONG
        );	
	set("have_flag", 1);
}