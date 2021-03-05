
inherit ROOM;
string bush();
void create()
{
        set("short", "断山坡");
        set("long", @LONG
这是一片长满灌木的山坡。低矮的树木重重叠叠，无路可行，更看不清后面有
什么。身后则是一片茂密的丛林。四外望只见山峦重叠，奇峰林立，景色秀丽，犹
如一幅山水图，让你浑然忘记身在何处。
LONG
        );
    	set("exits", ([ 
		"south" : __DIR__"milinop",
	]));
   	set("item_desc", ([
   		"灌木" : (: bush :),
   		"bush" : (: bush :),
   		"guanmu" : (: bush :),
   	]));
    	set("outdoors", "huashan");
	
	set("coor/x",-5);
	set("coor/y",-40);
	set("coor/z",27);
	setup();

}

string bush(){
	object me;
	me = this_player();
	tell_object(me, "灌木很密，似乎需要砍开才可以通行。（ｃｈｏｐ）\n");
	add_action("do_chop", "chop");
	return "";
}

int do_chop(string arg)
{
    	object obj, me, bush;
    	if(!arg || (arg!="bush" && arg != "灌木" && arg != "guanmu")){
    		return notify_fail("你要砍开什么？\n");
    	}
    	me = this_player();
    	obj = me->query_temp("weapon");
    	if( !obj ){
    		tell_object(me, "你空着手，怎么砍？\n");
    		return 1;
    	} else if( obj->query("flag") == 4 ) {
    		if( !query("exits/north") ) {
    			set("exits/north", __DIR__"guanmu");
    			message_vision(sprintf("$N用手中的%s砍出一条向北的路．\n",obj->name()),me);
			bush = find_object(__DIR__"guanmu");
			if(!objectp(bush)){
				bush = load_object(__DIR__"guanmu");
			}
			bush->set("exits/south", __DIR__"duanshan");
    			me->start_busy(1);
    		} else {
    			message_vision(sprintf("$N用手中的%s向灌木一顿乱砍．\n",obj->name()), me);
    		}
	} else {
		message_vision("$N对着灌木一通乱砍。\n", me);
	}
	call_out("close_path", 30);
	return 1;
}

void close_path(){
	object room;
	
	if(query("exits/north")){
		message("vision", "灌木的枝叶弹回挡住了北面的路。\n", this_object());
		delete("exits/north");
	}
	room = find_object(__DIR__"guanmu");
	if(!objectp(room)){
		room = load_object(__DIR__"guanmu");
	}
	if(room->query("exits/south")){
		message("vision", "灌木的枝叶弹回挡住了南面的路。\n", room);
		room->delete("exits/south");
	}
}
