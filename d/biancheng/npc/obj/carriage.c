#include <ansi.h>
inherit ITEM;

string look_outside(object ob, object env);

void create()
{
    	set_name("黑漆马车", ({ "carriage", "mache"}) );
    	set_weight(300000);
    	set("no_get", 1);
    	set("no_reset",1);
    	set_max_encumbrance(80000000);
    	set("unit", "辆");
    	set("short"," 马车(Carriage)");
	set("long", "一辆黑漆马车，车厢中舒服而干净，至少可以坐八个人。\n ");
    	set("closed", 1);
    	set("value", 2000);
    	::init_item();
}

int is_container() {return 1;}

void init()
{
    	add_action("do_open","open");
    	add_action("do_close","close");
	add_action("do_jump","jump");
	add_action("do_out","out");
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}

int do_close(string arg)
{
    	object	me;
    	me = this_player();
    	if(arg != "mache" && arg != "carriage")
        	return notify_fail("你要关上什么？\n");
	if (is_closed())
		return notify_fail("马车门已经关上了。 \n");
	message_vision("$N把车门关上了。\n", me);
    	this_object()->set("closed",1);
    	return 1;
}


int do_open(string arg)
{
    	object me, ob;
    	me = this_player();
	if(arg != "mache" && arg != "carriage")
	    return notify_fail("你要打开什么？\n");
	if (!is_closed())
		return notify_fail("车门是开着的。 \n");
	message_vision("$N将马车门打开。 \n", me);
	this_object()->set("closed",0);
	me->move(environment(this_object()));
    	return 1;
}

int do_out(string arg)
{
	object me,ob;
	me = this_player();
	if (environment(me) != this_object())
		return 0;
	if(arg != "mache" && arg != "carriage")
	    return notify_fail("你要走出什么？\n");
	if (objectp(ob=present("chefu",environment())))
        return notify_fail(ob->name()+"说道：坐好了，不要乱动！\n");
	if (is_closed()){
		message_vision("$N将马车门打开。 \n", me);
	}
	me->move(environment(this_object()));
	message_vision("$N从马车上走了下来。 \n", me);
	if (!is_closed()) {
		message_vision("车门自动关上了。 \n", me);
		this_object()->set("closed",1);
	}
	return 1;
}

int do_jump(string arg)
{
	object me, ob;
	
	me = this_player();
	if (environment(me) != this_object())
		return 0;
	if(arg != "mache" && arg != "carriage")
        	return notify_fail("你要跳下什么？\n");
    	if(is_closed())	{
		message_vision("$N将马车门打开心寒地向下看了看。\n", me);
	}
    	message_vision("$N咬了咬牙跳了下去。\n", me);
	me->move(environment(this_object()));
	message_vision("$N从马车上滚了下来，跌了一个四脚朝天。 \n",me);
	me->unconcious();
	if (!is_closed())
	{
		message_vision("车门自动关上了。 \n", this_object());
		this_object()->set("closed", 1);
	}
    return 1;
}


int move(mixed dest, int silently)
{
	object *inv;
	int i;
	::move(dest, silently);

	inv=all_inventory(this_object());
    	for(i=0;i<sizeof(inv);i++)
        if (userp(inv[i]))
		{	
			tell_object(inv[i],CYN"\n\n马车继续前行，拉开车帘向外望去，这里是   "NOR);
//			message_vision("马车外 \n",inv[i]);
			//copy whole base class function here isnot good. need think of a smart way:(.
			//call_other("/cmds/std/look"->look_room(inv[i],dest));
			message_vision((look_outside(inv[i],dest)),inv[i]);
			return 1;
		}
	return 1;
}


string look_outside(object me, object env) {
	int i;
	object *inv;
	mapping exits;
	string roomdesc, str, *dirs;

	if(!env) {
		return "你的四周灰蒙蒙地一片，什麽也没有。\n";
	}

	if (env->query("end")) return "\n";
	// room descriptions.

	str = sprintf(CYN"%s \n"NOR+"    %s",
			env->query("short"),
			env->query("long"),
			);
			//wizardp(target)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),
			//		env->query("coor/y"),env->query("coor/z")): "",
			//env->long(),
/*	str = sprintf( "%s \n    %s",
			env->query("short"),
			//wizardp(target)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),
			//		env->query("coor/y"),env->query("coor/z")): "",
			//env->long(),
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// exits.
	if(mapp(exits = env->query("exits"))) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++) {
			if((int)env->query_door(dirs[i], "status") & 1 ) {
				dirs[i] = 0;
			}
		}
		dirs -= ({ 0 });
		if(sizeof(dirs)==0) {
			str += "    这里没有任何明显的出路。\n";
		} else if(sizeof(dirs)==1) {
			str += "    这里唯一的出口是 " + BOLD + dirs[0] +NOR + "。\n";
		} else {
			str += sprintf("    这里明显的出口是 " + BOLD + "%s" +NOR + 
					" 和 " + BOLD + "%s" +NOR + "。\n",
					implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
		}
	} else {
		str += "    这里没有任何明显的出路。\n";
	}*/
	
	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]==me || inv[i]->query("no_shown") || !me->visible(inv[i])
			|| inv[i]->query("id")=="carriage" || inv[i]->query("id")=="chefu") {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}
