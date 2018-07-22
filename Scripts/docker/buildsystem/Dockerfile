FROM debian:7

VOLUME /opt/DeepNet-install

RUN "apt-get" update -y
RUN "apt-get" install -y \
    git \
    build-essential \
	flex bison \
	perl \
	libxml2-dev \
	libmysqlclient-dev \
	libpq-dev \
	libcurl3-dev \
	libmagic-dev \
	binutils libfcgi-dev \
	libfcgi++ libicu-dev libpcre3-dev \
	libxml-dom-perl libdbd-sqlite3-perl libdbi-perl \
	hunspell-tools libhunspell-dev

RUN GIT_SSL_NO_VERIFY=true git clone "https://imagebuilder:Iih5we4jieK2ieseOot6Ahha@gitlab.mo-sys.de/deepnet/DeepNet.git" "/opt/DeepNet"
WORKDIR /opt/DeepNet/Scripts
RUN "/opt/DeepNet/Scripts/make_all" -c -u -e -b "release"

ADD files/install_apps.sh /opt/
RUN chmod u+x /opt/install_apps.sh
#RUN /opt/install_apps.sh "release" "/opt/DeepNet-install" "/opt/DeepNet"