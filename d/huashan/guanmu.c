
inherit ROOM;
int fall(object me);
void create()
{
        set("short", "灌木丛");
        set("long", @LONG
四周都是低矮的灌木，重重叠叠的灌木让人无立足之处，许多灌木枝叶上都长
有尖尖的刺，当枝叶擦过你手臂脸颊，伴随而来的是一阵热辣辣的疼痛。
LONG
        );
 	set("objects", ([
 		__DIR__"obj/bush" : 1,
 	])); 
    set("outdoors", "huashan");

	set("coor/x",0);
	set("coor/y",-38);
	set("coor/z",27);
	setup();
}

void init(){
	object me;
	me = this_player();
	add_action("do_chop", "chop");
	if (!userp(me))	return;
		
	if( me->query_temp("followcrow")) {
		call_out("fall", 4, me);	
	} else if(!random(10)){
		call_out("fall", 4, me);
	}  
}

int fall(object me){
	object room;
	
	if(! me || !interactive(me) || environment(me) != this_object()){
		return 0;
	}
	tell_object(me, "你脚下一松，地面忽然塌了下去！在惊叫声中，你坠下山崖。\n");
	message("vision", "伴随着一声惊叫“阿~~~”，" + me->name() + "身形向崖下坠去。\n", 
			environment(me), me);
	room = find_object(__DIR__"yadi");
	if(!objectp(room)){
		room = load_object(__DIR__"yadi");
	}
	message("vision", "只听一声惊叫“阿~~~~~”随即一物落在你身旁。\n", room, me);
	me->move(room);
	me->unconcious();
}

int do_chop(string arg)
{
    object obj, me, room;
    if(!arg || (arg != "bush" && arg != "灌木" && arg != "guanmu")) {
    	return notify_fail("你要砍开什么？\n");
	}
    me = this_player();
    obj = me->query_temp("weapon");
    if( !obj ){
    	tell_object(me, "你空着手，怎么砍？\n");
    	return 1;
    } else if( obj->query("flag") == 4 ) {
    	if( !query("exits/south") ) {
    		set("exits/south", __DIR__"duanshan");
    		message_vision(sprintf("$N用手中的%s砍出一条向南的路．\n",obj->name()),
            		me);
			room = find_object(__DIR__"duanshan");
			if(!objectp(room)){
				room = load_object(__DIR__"duanshan");
			}
			room->set("exits/north", __DIR__"guanmu");
    		me->start_busy(1);
    	} else {
    		message_vision(sprintf("$N用手中的%s向灌木一顿乱砍．\n",obj->name()),
            		me);
    	}
	} else {
		message_vision("$N对着灌木一通乱砍。\n", me);
	}
	call_out("close_path", 30);
	return 1;
}

void close_path(){
	object room;
	
	if(query("exits/south")){
		message("vision", "灌木的枝叶弹回挡住了南面的路。\n", this_object());
		delete("exits/south");
	}
	room = find_object(__DIR__"duanshan");
	if(!objectp(room)){
		room = load_object(__DIR__"duanshan");
	}
	if(room->query("exits/north")){
		message("vision", "灌木的枝叶弹回挡住了北面的路。\n", room);
		room->delete("exits/north");
	}
}
