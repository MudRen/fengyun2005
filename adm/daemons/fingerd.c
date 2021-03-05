// fingerd.c

#include <net/dns.h>

void create() { seteuid( getuid() ); }

string age_string(int time)
{
	int month, day, hour;

	time /= 3600;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	month = time / 30;
	return (month?month + "月":"") + (day?day + "天":"") + hour + "小时";
}

string finger_all(int showage)
{
	object *ob;
	string msg;
	int i;

	ob = sort_array(users(),"sort_user",this_object());
	msg = "";
	for(i=0; i<sizeof(ob); i++) {
		if( this_player() && !this_player()->visible(ob[i]) ) continue;
		if( showage)
		msg = sprintf("%s%-10s  %-8s  %-15s (%s) %s\n",
			msg, ob[i]->query("name"), ob[i]->query("id"),
			age_string( (int)ob[i]->query("mud_age")), 
			query_ip_number(ob[i]),query_ip_name(ob[i]) );
		else
                msg = sprintf("%s%-20s  %-20s   \n",
                        msg, ob[i]->query("name"), ob[i]->query("id"),
                        );

	}
	return msg;
}

string finger_user(string name, int wizship)
{
	object ob, body;
	string msg="", mud;

	if( sscanf(name, "%s@%s", name, mud)==2 ) {
		GFINGER_Q->send_finger_q(mud, name, this_player(1));
		return "网路指令传送过程可能需要一些时间，请稍候。\n";
	}

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) return "没有这个玩家。\n";
	if( wizship ) {
	        if( objectp(body = find_player(name)) && geteuid(body)==name ) {
	                msg = sprintf("\n%s目前正在从 %s 连线中。\n", body->name(1),
	                        query_ip_name(body));
	        }
		msg +=  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
			"电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n"
			"合计在线时间：\t%s\n\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			ob->query("email"),
			ob->query("last_from"),
			ctime(ob->query("last_on")),
		(body ?	(age_string( (int)body->query("mud_age"))) : "不告诉你")
		);
			    }
	else
	{
	        if( objectp(body = find_player(name)) && geteuid(body)==name 
	        	&& !body->query("wiz_invis")) {
	                msg = sprintf("\n%s目前正在连线中。\n", body->name(1),
	                        ); }
	        msg +=  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
	                "上次连线时间：\t%s\n\n",
	                ob->query("id"),
	                ob->query("name"),
	                SECURITY_D->get_status(name),
	                ctime(ob->query("last_on"))
        );
		}
	destruct(ob);
	return msg;
}

varargs string remote_finger_user(string name, int chinese_flag)
{
	object ob, body;
	string msg;

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() )
		return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";
	if( chinese_flag ) msg =  sprintf(
		"\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
		"电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	else msg =  sprintf(
		"\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
		capitalize(ob->query("id")),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	if( body = find_player(name) ) {
		if( !this_player() || this_player()->visible(body) )
			msg += chinese_flag ?
				("\n" + ob->query("name") + "目前正在线上。\n"):
				("\n" + capitalize(name) + " is currently connected.\n");
	}

	destruct(ob);
	return msg;
}

object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) ) {
		// Check if the player is linkdead
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");
	}
	ob = new(LOGIN_OB);
	ob->set("id", id);
	return ob->restore() ? ob : 0;
}
int sort_user(object a, object b)
{
return strcmp(query_ip_name(a), query_ip_name(b));
} 

