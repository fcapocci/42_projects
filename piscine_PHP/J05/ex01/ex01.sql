CREATE TABLE IF NOT EXISTS db_fcapocci.`ft_table`
(
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `login` varchar(8) NOT NULL DEFAULT 'toto',
    `groupe` ENUM('staff', 'student', 'other') NOT NULL,
    `date_de_creation` date NOT NULL,
    PRIMARY KEY (`id`)
)   ENGINE=MyISAM DEFAULT CHARSET=latin1;
