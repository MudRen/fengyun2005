// magic_seal.c

inherit ITEM;

void create()
{
	set_name("符咒", ({"seal"}) );
	set_weight(5);
	set("long", "这是一张画好的符咒。\n");
	set("unit", "张");
	set("value", 0);
	set("fast_grab", 1);
}

int unequip()
{
	set("equipped", 0);
	return 1;
}

void init()
{
	add_action("do_attach", "attach");
	add_action("do_write", "write");
	add_action("do_burn", "burn");
}

int do_write(string arg)
{
	object obj, tarobj;
	string sheet, target;

	if( !arg || sscanf(arg, "%s on %s", target, sheet)!=2 ) {
		return notify_fail("指令格式：write <姓名> on <符咒>\n");
	}
	if( !objectp(obj = present(sheet, this_player())) ) {
		return notify_fail("你要使用哪张符咒？\n");
	}
	if( obj != this_object() ) {
		return 0;
	}
	if( environment(this_player())->query("no_magic") ) {
		return notify_fail("这里不可以用符咒。\n");
	}
	tarobj = find_living(target);
	if( !tarobj ) {
		message_vision("$N把" + target + "写在$n上。\n", this_player(), obj);
		obj->set("long", "这是一张" + obj->name() + "，上面写着＂" + target + "＂几个血字！\n");
	} else {
		message_vision("$N把" + tarobj->name() + "写在$n上。\n", this_player(), obj);
		obj->set("long", "这是一张" + obj->name() + "，上面写着＂" + tarobj->name() + "＂几个血字！\n");
	}
	obj->set("targetname", target);
	return 1;
}

int do_burn(string arg)
{
	string sheet, dest;
	object ob, sobj;
	function f;

	if( !arg || sscanf(arg, "%s", sheet)!=1 ) {
		return notify_fail("指令格式：burn <符咒>\n");
	}
	if( !objectp(sobj = present(sheet, this_player())) ) {
		return notify_fail("你要使用哪张符咒？\n");
	}
	if( !functionp(f = sobj->query("burn_func", 1)) ) {
		return notify_fail("这张符不可以烧。\n");
	}
	if( this_player()->is_busy() ) {
		return notify_fail("你现在没空烧符。\n");
	}
	if( this_player()->is_ghost() ) {
		return notify_fail("鬼魂不可以用符咒。\n");
	}
	if( environment(this_player())->query("no_magic") ) {
		return notify_fail("这里不可以用符咒。\n");
	}
	if( evaluate(f, sobj) ) {
		destruct(sobj);
		return 1;
	} else {
		return 0;
	}
}

int do_attach(string arg)
{
	string sheet, dest;
	object ob, sobj;
	function f;

	if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 ) {
		return notify_fail("指令格式：attach <符咒> to <目标>\n");
	}
	if( !objectp(sobj = present(sheet, this_player())) ) {
		return notify_fail("你要使用哪张符咒？\n");
	}
	ob = present(dest, this_player());
	if( !ob ) {
		ob = present(dest, environment(this_player()));
	}
	if( !ob ) {
		return notify_fail("你要对什麽东西使用这张符咒？\n");
	}
	if( environment(this_player())->query("no_magic") ) {
		return notify_fail("这里不可以用符咒。\n");
	}
	if( !functionp(f = sobj->query("attach_func", 1)) ) {
		return notify_fail("这张符不可以贴。\n");
	}
	if( evaluate(f, sobj, ob) ) {
		if( ob!=this_player() ) {
			message_vision("$N拿出一张" + name() + "往$n一贴。\n", this_player(), ob);
		}
		if( ob && ob->is_character() ) {
			sobj->move(ob);
			sobj->set("equipped", "sealed");
			sobj->set("no_drop", "这样东西不能丢弃，必须用 detach。\n");
		} else {
			destruct(sobj);
		}
		return 1;
	} else {
		return 0;
	}
}
