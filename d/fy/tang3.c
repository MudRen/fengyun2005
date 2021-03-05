inherit ROOM;
void create()
{
    set("short", "化尸堂");
    set("long", @LONG
金钱帮为铲除异己而双手血腥，结下了众多仇家。虽然重金买通官府，对帮中
的所作所为大都视而不见，但江湖仇怨无休无止，为掩人耳目，金钱帮的化尸堂正
是焚烧罪状和尸体的处所。两人高的青铜炉火焰正盛。一股焦尸的恶臭弥漫了整个
大厅（ｂｕｒｎ）。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"jhuang",
      ]));

    set("item_desc", ([
	"青铜炉":"两人高的青铜炉，熊熊火焰燃烧得正旺，一碰就会烫得皮开肉绽。似乎可以移动。\n",
	"ding": "两人高的青铜炉，熊熊火焰燃烧得正旺，一碰就会烫得皮开肉绽。似乎可以移动。\n",
	"lu": "两人高的青铜炉，熊熊火焰燃烧得正旺，一碰就会烫得皮开肉绽。似乎可以移动。\n",
	"oven": "两人高的青铜炉，熊熊火焰燃烧得正旺，一碰就会烫得皮开肉绽。似乎可以移动。\n",
      ]));

    set("coor/x",-180);
    set("coor/y",120);
    set("coor/z",0);
    set("map","fywest");
    setup();
}


void init()
{
    add_action("do_burn","burn");
    add_action("do_move",({"move","push"}));

}



int do_burn(string arg)
{
    object me;
    object tar;
    int score, pot, num;
    me = this_player();

    num = 900;

    if( !arg || arg == "") 
	return notify_fail("你烧啥东西．\n");
    tar = present(arg, me);
    if( !tar) 
	return notify_fail("你身上没有这东西．\n");
    if( userp(tar))
	return notify_fail("你不可烧活的东西．\n");
    if( tar->query("owner"))
	return notify_fail("你不可烧订的东西．\n");
    if (tar->query("no_burn"))
	return notify_fail("这样东西不能烧。\n");

    //	TO prevernt roboting burning corpse
    //	(1) unlimited spawn corpse cannot be burnt
    //	(2) You can gain 10 "corpse" every 15 minutes.
/*
    if( tar->is_corpse() && !tar->query("possessed"))		
    {
	if  (me->query("timer/burn")+ num < time()) 
	    me->set("timer/burn_corpse",0);

	if (!me->query("timer/burn_corpse") ) 
	    me->set("timer/burn",time());

	if (me->query("timer/burn")+ num < time() || me->query("timer/burn_corpse") < 10){
	    me->add("potential",  1);
	    me->add("timer/burn_corpse",1);
	}
  	}*/
    message_vision("$N将$n投入了青铜炉，$n转眼化为灰烬．\n", me, tar);
    tar->move(environment(me));
    destruct(tar);
    return 1;
}



int do_move(string arg)
{
    string msg;
    object room;
    if (!arg || (arg!= "青铜炉" && arg!= "ding" && arg!= "lu" && arg!="oven"))
	return notify_fail("你想移动什么？\n");

    if (this_player()->query("force_factor")<60)
	return notify_fail("你用尽全力推去，青铜炉象生了根似的，纹丝不动。\n");

    msg= this_player()->query("gender")=="男性" ?
    "\n$N大喝一声，运力于掌，缓缓移开青铜炉。 \n"
    : "\n$N娇叱一声，临空一腿击在炉身，青铜炉竟然向旁移开了半尺。\n";
    message_vision(msg, this_player());
    message("vision","一股灼人的热炎挟着黑烟迎面扑来，烟雾散去，"+this_player()->name()+"忽然从屋中消失了。\n",this_object(),this_player());
    tell_object(this_player(),"一股灼人的热炎挟着黑烟迎面扑来，你似乎觉得脚下的青石砖移动了起来。\n\n\n");
    room = find_object(AREA_MAZE"jq3-entry");
    if (!room) room = load_object(AREA_MAZE"jq3-entry");
    this_player()->move(room);
    return 1;
}



