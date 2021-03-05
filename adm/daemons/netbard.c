#define NETBAR_SITES "/adm/etc/netbar_sites"
#define NETBARN_SITES "/adm/etc/netbarn_sites"
#define NETBAR_UNLIMIT "/adm/etc/netbar_unlimit"

void load_sites();
void add(string pattern);
void delete(string pattern);
int  is_netbar(string site);
int save_site(string filename, string *data);
void print();

string *Sites;			// 允许的Site
string *NOSites;		// 不允许的Site
string *OKSites;		// 即使有NETBAR也没有ip限制的地址

// To simplify, just use regexp and first 3 digit check.
// Errors will occur when 24.24.17.22 meets a 24.17.22.* , which shouldn't happen too frequently :)

int enforced = 1;		// Whether it's enforced.

void create()
{
	seteuid(getuid());
	load_sites();
}

void load_sites()
{
	string *tmp, file;
	int loop;

	Sites = ({});
	NOSites = ({});	
	OKSites = ({});
	
	// reads in the list of the netbar sites
	file = read_file(NETBAR_SITES);
	if (file) {
		tmp = explode(file, "\n");
   		for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else if (member_array(tmp[loop],Sites)==-1)
        		Sites += ({ tmp[loop] });
		save_site(NETBAR_SITES, Sites);
	}
	
    // reads in the list of the not netbar sites
    file = read_file(NETBARN_SITES);
    if (file) {
	    tmp = explode(file, "\n");
	    for(loop=0; loop<sizeof(tmp); loop++)
	         if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
	         	continue;
	         else if (member_array(tmp[loop],NOSites)==-1) 
	           	NOSites += ({ tmp[loop] });
	   	save_site(NETBARN_SITES, NOSites);         	
	}
	
	// reads in the list of the unlimited sites
    file = read_file(NETBAR_UNLIMIT);
    if (file) {
    	tmp = explode(file, "\n");
    	for(loop=0; loop<sizeof(tmp); loop++)
            if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                    continue;
            else if (member_array(tmp[loop],OKSites)== -1)
            	OKSites += ({ tmp[loop] });
	   	save_site(NETBAR_UNLIMIT, OKSites);         	
	}
		
	return;
}

int save_site(string filename, string *data) {
	int i/*, j*/, num;
	string comment;
//	string *field_2;
	
	num = sizeof(data);
	
	comment = "#" + filename + "\n";
	if( !write_file(filename, comment,1))
		return 0;
	
	for (i=0;i<num;i++) {
		if (!write_file(filename,(data[i]+"\n")))
				return 0;
	}
	
	write_file(filename,"\n");
	write("NETBAR列表更新完毕。\n");
	return 1;
}

int is_netbar(string site)
{
	string *line;
	int i;

	if (!enforced)	return 1;
    
    if (sizeof(OKSites))
    if (member_array(site,OKSites) != -1)		// this requires exact match
    	return 1;
    	
	line = ({});
	line += ({site});

    for (i = 0; i < sizeof(NOSites); i++)
    if (sizeof(regexp(line, NOSites[i])) == 1
    	 && line[0][0..2] == NOSites[i][0..2])
    	return 0;

	for (i = 0; i < sizeof(Sites); i++)
		if (sizeof(regexp(line, Sites[i])) == 1
			 && line[0][0..2] ==Sites[i][0..2])
			return 1;
	return 0;
}	

void print()
{
	int i;
	write("****	UNLIMITED	****\n");
	for (i = 0; i < sizeof(OKSites); i++)
		write(OKSites[i] + "\n");
	write("****	NETBAR	****\n");
	for (i = 0; i < sizeof(Sites); i++)
		write(Sites[i] + "\n");
	write("****	NETBARN	****\n");
    for (i = 0; i < sizeof(NOSites); i++)
        write(NOSites[i] + "\n");
}

void add(string site)
{
//	string filename;
	
	if (member_array(site,Sites)== -1)
	{
		Sites += ({site});
		save_site(NETBAR_SITES, Sites);
		write("将"+site+"加入NETBAR。\n");
	}else
		write("NETBAR已经有该项地址了。\n");
}

void add_ban(string site) {
    if (member_array(site,NOSites)== -1) 
	{
		NOSites += ({site});
		save_site(NETBARN_SITES, NOSites);
		write("将"+site+"加入NETBARN中。\n");
	}else
		write("NETBARN已经有该项地址了。\n");
}

void delete(string site)
{
//  int i;
	if (member_array(site,Sites)!= -1)
	{
		Sites -= ({site});
		save_site(NETBAR_SITES, Sites);
		write("将"+site+"从NETBAR中清除。\n");
	} else
		write("NETBAR中没有该项地址。\n");
    
}
void delete_ban(string site)
{
//  int i;
	if (member_array(site,NOSites)!= -1)
	{
		NOSites -= ({site});
		save_site(NETBARN_SITES, Sites);
		write("将"+site+"从NETBARN中清除。\n");
	} else
		write("NETBAR中没有该项地址。\n");
    
}


void add_all(string site) {
    
    if (member_array(site,NOSites)!= -1)
	{
		NOSites -= ({site});
		save_site(NETBARN_SITES, Sites);
		write("将"+site+"从NETBARN中清除。\n");
	} 	
    
    if (member_array(site,OKSites)== -1) {
    	OKSites += ({ site });
		save_site(NETBAR_UNLIMIT, OKSites);
		write("将"+site+"加入NETBARN_UNLIMIT中。\n");
	}else
		write("NETBAR_UNLIMIT已经有该项地址了。\n");
}

void delete_all(string site){
	
	if (member_array(site,OKSites)!= -1) 
	{
		OKSites -= ({site});
		save_site(NETBAR_UNLIMIT, OKSites);
		write("将"+site+"从NETBAR_UNLIMIT中清除。\n");
	} else
		write("NETBAR_UNLIMIT中没有该项地址。\n");
}

void dynamic_add(string site)
{
		Sites += ({site});
}

void dynamic_remove(string site)
{
		NOSites += ({site});
}

//	Netbar switch
int netbar_switch(){
	if (enforced==0) {
		enforced = 1;
		CHANNEL_D->do_sys_channel("sys","NETBAR is ENFORCED, 3 IDs Per IP.\n");
	}
	else {
		enforced = 0;
		CHANNEL_D->do_sys_channel("sys","NETBAR is TEMPEROARY DISABLED, NO ID NUM LIMIT.\n");
	}
	return enforced;
}

int netbar_stat()
	{
	return enforced;
}
