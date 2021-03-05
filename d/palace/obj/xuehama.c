inherit ITEM;

void create()
{
  	set_name("雪蛤蟆",({"snowfrog","snow frog"}));
  	set("long", "这是一只冰清玉洁的雪蛤蟆。\n");
  	set("value",100);
  	set("unit","只");
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure","cure");
}

int do_cure()
{
	object me;
	me = this_player();
	message_vision("$N把雪蛤蟆用手捏碎后服了下去！\n",me);
	me->clear_condition();
        message_vision("$N的腹内＂隆隆＂作响！\n",me);
	destruct(this_object());
  	return 1;
}
