#define X_COOR 0
#define Y_COOR 0
#define Z_COOR 0
#define R_FLAG 0
#define FREE_SPACE 4
#define BASIC_TAX 0
#define BASIC_SCORE_TAX 0
#define OWNER "bigtie7001"
#define TIMESTAMP "anniestamp"
#define CLASS "bigwiz7001"

#include <ansi.h>

inherit XROOM;
inherit F_ANNIE;

int restore();
int restore_item();

void create()
{
set("short", "SHORT_TITLE");
set("long", @LONG
LONG_TITLE
LONG
);
        set("exits", ([
]));
set("objects", ([
       ]) );
	set("coor/x",X_COOR);
	set("coor/y",Y_COOR);
	set("coor/z",Z_COOR);
	set("room_flag",R_FLAG);
	set("owner", OWNER);
	set("class", CLASS);
	set("timestamp",TIMESTAMP);
	set("free_space",FREE_SPACE);
	setup();

}
void init()
{
	int flag;
	flag = (int) query("room_flag");
	if(flag & 1) set("valid_startroom",1);
	if(flag & 2) set("NONPC",1);
	if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
	if(flag & 16) set("outdoors","residence");

	if (!query("already_loaded"))
	{
		set("already_loaded",1);
		restore();
		restore_item();	// annie' item-save
	}

	add_action("do_invite","invite");
	add_action("do_setowner","setowner");
	add_action("do_share","share");
}

int is_owner(string arg)
{
	if (arg == query("owner"))
		return 1;
	if (arg == OWNER)
		return 1;
	if (arg == query("couple"))
		return 1;
	return 0;
}

int valid_enter(object me)
{
	int flag;
// means no enter at the beginning.
	int enter = 0;
        flag = (int) query("room_flag");
// always let owner go in:
	if((string)me->query("id") == (string)query("owner"))
	enter = 1;
        if(flag & 16)
	enter = 1;
	if(flag & 512)
	if((string)me->query("id") == (string)query("owner"))
	enter = 1;
	if(flag & 1024)
        if((string)me->query("class") == (string)query("class"))
        enter = 1;
	if(flag & 2048)	
		if(query_temp("invite/"+me->query("id")))
			enter = 1;	
	return enter;
}

int do_invite(string arg)
{
	object me;
	mapping invite_list;
	int i;
	string *lists;
	me= this_player();
	if(!is_owner(me->query("id")))
		return 0;
	if (arg)
	{
		set_temp("invite/"+arg,1);
		write("你邀请"+arg+"来你的房间。\n");
		return 1;
	}
	invite_list = query_temp("invite");
	write(WHT"\t　　邀请名单：\n"NOR);
	write(HIR BLK"────────────────\n"NOR);
	if( !mapp(invite_list) || !sizeof(invite_list) )
	{
		write("没有邀请任何人。\n");
		write(HIR BLK"────────────────\n"NOR);
		return 1;
	}
	lists = keys(invite_list);
	for(i=0; i<sizeof(lists); i++)
		write(lists[i]+"\n");
	write(HIR BLK"────────────────\n"NOR);
	return 1;
}

int do_setowner(string arg)
{
	string oldowner;
	if (!wizardp(this_player()) && !is_owner(this_player()->query("id")))
		return 0;
	oldowner = (string)query("owner");
	set("owner",arg);
	write("你将房间的主人暂时设为"+arg+"。\n");
	call_out("set_back",60, oldowner);
	return 1;
}

int do_share(string arg)
{
	object me;
	me= this_player();
	if((string)me->query("id") != (string)OWNER)
		return 0;
	if (!me->query("marry") )
		return notify_fail("你只能与你的另一半分享房间。\n");
	set("couple",me->query("marry"));
	write("你添加了房间的第二主人："+me->query("marry")+"。\n");
	return 1;
}

int set_back(string oldowner)
{
	set("owner", oldowner);
	return 1;
}


string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+".room"+query("timestamp")+".o");
}

int save()
{
        string file;
        int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                return result;
        }
        return 0;
}
int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
                return 1;
        return 0;
}

int restore_item()
{
	object box,item;
	mapping item_list;
	string *lists,mitem;
	int i,idx;
/*
	box = new("/obj/item/box");
	box->move(this_object());

	item_list = query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return 1;
	// 没有任何东西。

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = query("item_list/"+lists[i]);
		item = new(mitem["item_basename"]);
		annie_itemmimic(item,mitem["data"],mitem["temp_data"]);
		item->set_name(mitem["item_name"],mitem["item_id"]);
		item->set_amount(mitem["amount"]);
		item->move(box);
	}
*/
	item_list = query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return 1;
	// 没有任何东西。

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = query("item_list/"+lists[i]);
		item = new(mitem);
		item->move(this_object());
		item->set("no_reset",1);
		item->restore_item();
	}
	return 1;
}

void reset()
{
	object *inv;
	int i;
	::reset();

	inv = all_inventory(this_object());
	for (i=0;i<sizeof(inv) ;i++ )
	{
		if (!inv[i]->query("item_type"))	continue;
		inv[i]->reset_item_list();	// save
	}
	return ;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
