inherit ROOM;
#include <ansi.h>
string show_book();

void create()

{
        set("short", "星星小屋");
        set("long", @LONG
屋子里的摆设很简单，也很精致，正中墙上挂着一幅画，画上一个穿着鲜红斗
篷的女子坐在河边，脸色苍白得可怕。鲜红的斗篷，如流水般飘动，漆黑的头发在
风中飞舞，明亮的眼睛中，带着种说不出的惆怅。画的左下角有一排小字。汉玉的
案几上放着一本翻开的书。
LONG
    );
        set("exits", ([ 
		"out": __DIR__"star_room2",
		"up" : __DIR__"star_room",
		"south": __DIR__"star_room3",
	]));
        set("item_desc", ([
    		"小字":	WHT"
    这是一首汉乐府，“上邪！我欲与君相知，长命无绝衰。山无陵，江水为竭，
冬雷震震，夏雨雪，天地合，乃敢与君绝！ ”\n\n"NOR,
		"picture":	WHT"
    这是一首汉乐府，“上邪！我欲与君相知，长命无绝衰。山无陵，江水为竭，
冬雷震震，夏雨雪，天地合，乃敢与君绝！ ”\n\n"NOR,      		    	
		"画":	WHT"
    这是一首汉乐府，“上邪！我欲与君相知，长命无绝衰。山无陵，江水为竭，
冬雷震震，夏雨雪，天地合，乃敢与君绝！ ”\n\n"NOR,      		    	
		"book": (: show_book() :),
		"翻开的书": (: show_book() :),
		"书": (: show_book() :),
	]) );
        set("coor/x",-1690);
        set("coor/y",640);
        set("coor/z",0);
        set("no_fly",1);
	set("map","zbwest");
	setup();

}


string show_book() {
	tell_object(this_player(),"
    这是一本李后主的词集，里面有一只蝴蝶，这蝴蝶看起来还栩栩如生，仿佛随
时都可能展动双翼，乘风而去。翻开词集，就看到了这只蝴蝶，看到那一页的词。"+HIR"

    林  花  谢  了  春  红  太  匆  匆"NOR+ "

    花谢了还会再开，春天去了还会回来。可是这蝴蝶呢？
    这首词几乎和蝴蝶同样美，足以流传千古，永垂不朽。可是这填词的人呢？
    这填词的人，生命是不是和蝴蝶—样？
    若人太多情，是不是就会变得和蝴蝶—样？\n\n"NOR);
    return "";
}

int valid_leave(object obj, string dir){
	
	object room,*env,*pc;
	
	if (dir=="south") {
		if (!objectp(room=find_object(__DIR__"star_room3")))
			room=load_object(__DIR__"star_room3");
		env=all_inventory(room);
		pc=filter_array(env,(: userp($1) :) );
		if (pc && sizeof(pc)) 
			return notify_fail("小蝶正忙着，等一会儿再进去吧。\n");
	}
	return 1;
}
		