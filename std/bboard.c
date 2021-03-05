// bboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void setup()
{
	string loc;

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
        set("no_reset",1);
	restore();
}

void init()
{
	add_action("do_post", "post");
	add_action("do_read", "read");
	add_action("do_look", "look");
	add_action("do_discard", "discard");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ 没有任何留言 ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf("%s [ %d 张留言，%d 张未读 ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ %d 张留言 ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
//	int i,last_time_read;
	string msg/*, myid*/;

	notes = query("notes");
	msg = query("long");
	msg = msg + "留言版的使用方法请见 help board。\n";
//┌──────────────────┐
/*

	if( !pointerp(notes) || !sizeof(notes) ) return query("long");

	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=0; i<sizeof(notes); i++)
		msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
			( notes[i]["time"] > last_time_read ? HIY: ""),
			i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15] );
*/	
	return msg;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
    int i;
    string *lines;    
	mapping *notes;

        if (! stringp(text))
                return;

        if (strlen(text) > 32 * 1024)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "你的留言中短句太多了，请调整一下以便他人阅读。\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 40 && !wizardp(me))
                {
                        tell_object(me, "你留言中有些行太长了，请分行以便他人阅读。\n");
                        return;
                }
        }
	
	log_file("BOARD_LOG",
sprintf("标题：%-40s %s(%s)\n----------------------------------------------------------------------\n",
note["title"],note["author"],ctime(note["time"])));
	log_file("BOARD_LOG",text);	
	log_file("BOARD_LOG","\n");
	note["msg"] = text;
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

	set("notes", notes);
	tell_object(me, "留言完毕。\n");

	save();
	return;
}

int do_post(string arg)
{
	mapping note;
	if(!arg) return notify_fail("留言请指定一个标题。\n");
	
	note = allocate_mapping(4);
	note["title"] = arg;
	note["author"] = this_player()->query("name")
	+"("+this_player()->query("id")+ ")";
	note["time"] = time();
	this_player()->edit( (: done_post, this_player(), note :) );
	return 1;
}

int do_read(string arg)
{
	int num;
	mapping *notes, last_read_time;
	string myid;

	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("留言板上目前没有任何留言。\n");

	if( !arg ) return notify_fail("指令格式：read <留言编号>|new|next\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
			
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要读第几张留言？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	this_player()->start_more("", sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
		num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
		+ notes[num]["msg"], 0);

	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}


int do_discard(string arg)
{
	mapping *notes;
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：discard <留言编号>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	if( notes[num]["author"] != (string) 
	this_player()->query("name")
        +"("+this_player()->query("id")+ ")"
	&&	(string)SECURITY_D->get_status(this_player(1)) != "(arch)"  && (string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
		return notify_fail("这个留言不是你写的。\n");

	if(sizeof(notes) == 1){
	    notes = 0;
	} else if(num == 0) {
	    notes = notes[num+1..sizeof(notes)-1];
	} else {
	    notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	}
	set("notes", notes);
	save();
	write("删除第 " + (num+1) + " 号留言....Ok。\n");
	return 1;
}


int do_look(string arg) {
	
	mapping *notes;
	int i,j, notes_total,last_time_read, safe, last_time_look;
	string msg;
	object me;
	me = this_player();
	
	
	if (!arg || (arg != ((string) query("id")))) return 0;
	
    	
    	notes = query("notes");
	
	if( !pointerp(notes) || !sizeof(notes) )  return 0;


    	last_time_read = me->query("board_last_read/" + (string)query("board_id"));
	last_time_look =(int) me->query_temp("last_time_look");
	notes_total= sizeof(notes);
	j = last_time_look;
	safe =0;
	msg=long();
    for(i=0; j<notes_total && i<50; i++) {
		msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
			( notes[j]["time"] > last_time_read ? HIY: ""),
			j+1, notes[j]["title"], notes[j]["author"], ctime(notes[j]["time"])[0..24] );
		j++;
		safe++;
		if (safe>500) return 0;
	}
    
	if (j<notes_total) {
//	    this_player()->start_more("",sprintf("%s", msg), 0);
		me->set_temp("last_time_look", j);
		msg += "\n--------------------------------------------------------------------\n留言版的使用方法请见 help board。\n"YEL"留言太多，列表一眼看不完。你可以再看看还有什么没看到的。\n"NOR;
	}
	else {
		me->delete_temp("last_time_look");
        msg += "\n--------------------------------------------------------------------\n留言版的使用方法请见 help board。\n";
	}
	tell_object(me, msg);
	return 1;
}